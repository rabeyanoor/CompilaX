import { useEffect, useRef } from 'react';
import * as d3 from 'd3';

// ── Collect siblings linked by `next` into an array
function collectChain(node) {
  const out = [];
  let cur = node;
  while (cur) {
    out.push(cur);
    cur = cur.next;
  }
  return out;
}

// ── Determine if a node is a leaf (value-holder)
function isLeaf(n) {
  return n.type === 'Literal' || n.type === 'Identifier';
}

// ── Pretty label for a node
function getLabel(n) {
  switch (n.type) {
    case 'Program':         return 'program';
    case 'VarDecl':         return `let ${n.value ?? ''}`;
    case 'Assignment':      return `${n.value ?? ''} =`;
    case 'IfStatement':     return 'if';
    case 'WhileStatement':  return 'while';
    case 'PrintStatement':  return 'print';
    case 'ReturnStatement': return 'return';
    case 'BinaryExpression':return n.value ?? '?';
    case 'UnaryExpression': return n.value ?? '?';
    case 'Identifier':      return n.value ?? '?';
    case 'Literal':         return n.value ?? '?';
    case 'Block':           return 'block';
    case 'ForStatement':    return 'for loop';
    case 'CallExpression':  return `${n.value}()`;
    case 'ArgList':         return 'args';
    default:                return n.type ?? '?';
  }
}

// ── Convert raw AST JSON → D3 hierarchy data
function toD3(node) {
  if (!node) return null;

  const d = { name: getLabel(node), rawType: node.type, isLeaf: isLeaf(node) };
  const ch = [];

  switch (node.type) {
    case 'Program': {
      const stmts = collectChain(node.left);
      stmts.forEach(s => { const c = toD3({ ...s, next: null }); if (c) ch.push(c); });
      break;
    }
    case 'Block': {
      const stmts = collectChain(node.left);
      stmts.forEach(s => { const c = toD3({ ...s, next: null }); if (c) ch.push(c); });
      break;
    }
    case 'VarDecl':
    case 'Assignment':
    case 'PrintStatement':
    case 'ReturnStatement': {
      if (node.left) { const c = toD3(node.left); if (c) ch.push(c); }
      break;
    }
    case 'IfStatement': {
      if (node.left) ch.push({ name: 'cond', rawType: 'meta', isLeaf: false,
        children: [toD3(node.left)].filter(Boolean) });
      if (node.mid)  ch.push({ name: 'then', rawType: 'meta', isLeaf: false,
        children: [toD3(node.mid)].filter(Boolean) });
      if (node.right) ch.push({ name: 'else', rawType: 'meta', isLeaf: false,
        children: [toD3(node.right)].filter(Boolean) });
      break;
    }
    case 'WhileStatement': {
      if (node.left) ch.push({ name: 'cond', rawType: 'meta', isLeaf: false,
        children: [toD3(node.left)].filter(Boolean) });
      if (node.mid)  ch.push({ name: 'body', rawType: 'meta', isLeaf: false,
        children: [toD3(node.mid)].filter(Boolean) });
      break;
    }
    case 'BinaryExpression': {
      if (node.left)  { const c = toD3(node.left);  if (c) ch.push(c); }
      if (node.right) { const c = toD3(node.right); if (c) ch.push(c); }
      break;
    }
    case 'ForStatement': {
      if (node.left) ch.push({ ...toD3(node.left),  label: `init: ${toD3(node.left).label}` });
      if (node.mid)  ch.push({ ...toD3(node.mid),   label: `cond: ${toD3(node.mid).label}` });
      if (node.right) {
        // node.right is the 'tail' which is a NODE_PROGRAM of update and statement
        const tail = node.right;
        if (tail.left) ch.push({ ...toD3(tail.left), label: `step: ${toD3(tail.left).label}` });
        if (tail.mid)  ch.push({ ...toD3(tail.mid),  label: `body` });
      }
      break;
    }
    case 'CallExpression': {
      if (node.left) {
        const args = collectChain(node.left);
        args.forEach((a, i) => {
          ch.push({ ...toD3(a), label: `arg[${i}]` });
        });
      }
      break;
    }
    default:
      if (node.left)  { const c = toD3(node.left);  if (c) ch.push(c); }
      if (node.mid)   { const c = toD3(node.mid);   if (c) ch.push(c); }
      if (node.right) { const c = toD3(node.right); if (c) ch.push(c); }
  }

  if (ch.length > 0) d.children = ch;
  return d;
}

// ── D3 Tree Renderer
function renderTree(svgEl, data) {
  const svg    = d3.select(svgEl);
  svg.selectAll('*').remove();

  const W = svgEl.clientWidth  || 900;
  const H = svgEl.clientHeight || 600;

  const root  = d3.hierarchy(data);
  const nodes = root.descendants().length;

  // Dynamic sizing
  const nodeW = 90;
  const nodeH = 42;
  const levelGap = 90;
  const siblingGap = Math.max(nodeW + 24, (W - 80) / Math.max(nodes / 3, 1));

  const treeLayout = d3.tree()
    .nodeSize([nodeW + 24, levelGap])
    .separation((a, b) => (a.parent === b.parent ? 1.2 : 1.8));

  treeLayout(root);

  // Center the tree
  const xs = root.descendants().map(d => d.x);
  const ys = root.descendants().map(d => d.y);
  const minX = Math.min(...xs);
  const maxX = Math.max(...xs);
  const minY = Math.min(...ys);
  const maxY = Math.max(...ys);
  const treeW = maxX - minX + nodeW;
  const treeH = maxY - minY + nodeH;

  const initialScale = Math.min(1, W / (treeW + 100), H / (treeH + 100));
  const initialX = (W - treeW * initialScale) / 2 - minX * initialScale + (nodeW * initialScale) / 2;
  const initialY = 40;

  const g = svg.append('g');

  const zoom = d3.zoom()
    .scaleExtent([0.1, 3])
    .on('zoom', e => g.attr('transform', e.transform));

  svg.call(zoom);

  // Set initial zoom transform without triggering transition
  svg.call(zoom.transform, d3.zoomIdentity.translate(initialX, initialY).scale(initialScale));

  // Hint text
  svg.append('text')
    .attr('x', W - 10)
    .attr('y', 20)
    .attr('text-anchor', 'end')
    .attr('class', 'ast-hint')
    .style('font-size', '10px')
    .style('fill', 'var(--text-muted)')
    .style('pointer-events', 'none')
    .text('Scroll / Pinch to zoom');

  // Links
  g.append('g').selectAll('path')
    .data(root.links())
    .join('path')
    .attr('class', 'ast-link')
    .attr('d', d3.linkVertical().x(d => d.x - minX).y(d => d.y));

  // Nodes
  const node = g.append('g').selectAll('g')
    .data(root.descendants())
    .join('g')
    .attr('class', d => `ast-node ${d.data.isLeaf ? 'leaf' : d.data.rawType === 'meta' ? 'intermediate' : ''}`)
    .attr('transform', d => `translate(${d.x - minX},${d.y})`);

  const halfW = nodeW / 2;
  const halfH = nodeH / 2;

  node.append('rect')
    .attr('x', -halfW)
    .attr('y', -halfH)
    .attr('width', nodeW)
    .attr('height', nodeH)
    .attr('rx', 6);

  node.append('text')
    .attr('text-anchor', 'middle')
    .attr('dominant-baseline', 'middle')
    .attr('y', 1)
    .text(d => {
      const label = d.data.name;
      return label.length > 12 ? label.slice(0, 11) + '…' : label;
    });
}

export default function ASTPanel({ ast }) {
  const svgRef = useRef(null);

  useEffect(() => {
    if (!ast || !svgRef.current) return;
    const d3data = toD3(ast);
    if (d3data) renderTree(svgRef.current, d3data);
  }, [ast]);

  return (
    <div className="panel">
      <div className="panel-header">
        <span className="panel-title">Abstract Syntax Tree</span>
        <span className="panel-count" style={{ fontSize: '11px', color: 'var(--text-muted)' }}>
          {ast ? 'Scroll / Pinch to zoom' : ''}
        </span>
      </div>

      <div className="ast-svg-container">
        {!ast && (
          <div className="ast-empty">
            <div className="ast-empty-icon">🌳</div>
            <p>Run code to visualize the Abstract Syntax Tree</p>
          </div>
        )}
        <svg ref={svgRef} width="100%" height="100%" />
      </div>
    </div>
  );
}
