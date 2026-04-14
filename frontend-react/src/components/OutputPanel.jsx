// Extract variable declarations from AST (traverse all VarDecl nodes)
function extractVars(node, result = {}) {
  if (!node) return result;
  if (node.type === 'VarDecl' && node.value) {
    const valNode = node.left;
    let val = '?';
    if (valNode) {
      if (valNode.type === 'Literal')    val = valNode.value ?? '?';
      else if (valNode.type === 'Identifier') val = valNode.value ?? '?';
      else val = valNode.type ?? '?';
    }
    result[node.value] = val;
  }
  // Recurse
  extractVars(node.left,  result);
  extractVars(node.mid,   result);
  extractVars(node.right, result);
  extractVars(node.next,  result);
  return result;
}

export default function OutputPanel({ output, error, ast, success, variables }) {
  const vars = variables && Object.keys(variables).length > 0 
    ? variables 
    : (ast ? extractVars(ast) : {});
  const hasVars = Object.keys(vars).length > 0;

  // Build console lines
  const lines = [];
  if (success === null) {
    lines.push({ cls: 'info', text: 'AetherScript Compiler — ready. Run code to see output.' });
  } else if (success) {
    lines.push({ cls: 'success', text: '> Execution successful.' });
    if (output) {
      output.split('\n').filter(Boolean).forEach(l => lines.push({ cls: 'output', text: l }));
    }
  } else {
    lines.push({ cls: 'error', text: '> Compilation failed.' });
    if (error) {
      error.split('\n').filter(Boolean).forEach(l => lines.push({ cls: 'error', text: l }));
    }
  }

  return (
    <div className="panel">
      <div className="panel-header">
        <span className="panel-title">Execution Output</span>
        <div style={{ display: 'flex', gap: '8px' }}>
          <button 
            className="icon-btn" 
            title="Copy Output"
            onClick={() => {
              const text = lines.map(l => l.text).join('\n');
              navigator.clipboard.writeText(text);
            }}
          >
            copy
          </button>
        </div>
      </div>

      <div className="output-split">
        {/* Console */}
        <div className="console-body">
          {lines.length === 0 ? (
            <div className="console-empty">No output yet.</div>
          ) : (
            lines.map((l, i) => (
              <div key={i} className={`console-line ${l.cls}`}>{l.text}</div>
            ))
          )}
        </div>

        {/* State Inspector */}
        <div className="state-inspector">
          <div className="state-header">State Inspector</div>
          {!hasVars ? (
            <div style={{ padding: '14px 18px', fontSize: '12px', color: 'var(--text-muted)' }}>
              No variables declared yet.
            </div>
          ) : (
            <table className="state-table">
              <thead>
                <tr>
                  <th>Variable</th>
                  <th>Value</th>
                </tr>
              </thead>
              <tbody>
                {Object.entries(vars).map(([name, value]) => (
                  <tr key={name}>
                    <td className="col-var">{name}</td>
                    <td className="col-val">{value}</td>
                  </tr>
                ))}
              </tbody>
            </table>
          )}
        </div>
      </div>
    </div>
  );
}
