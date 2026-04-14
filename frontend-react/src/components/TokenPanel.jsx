// Map token type string → CSS class
function getTokenClass(type) {
  const t = type.toUpperCase();
  if (t === 'KEYWORD') return 'KEYWORD';
  if (t === 'OPERATOR') return 'OP';
  if (t === 'IDENTIFIER') return 'IDENT';
  if (t === 'NUMBER') return 'NUMBER';
  if (t === 'STRING') return 'STRING';
  if (t === 'SYMBOL') return 'SYMBOL';
  return 'DEFAULT';
}

// Friendly display label
function getTokenLabel(token) {
  const t = token.type.toUpperCase();
  const v = token.value ?? '';

  if (t === 'IDENTIFIER') return `ID(${v})`;
  if (t === 'NUMBER')     return `NUM(${v})`;
  if (t === 'STRING')     return `"${v}"`;
  if (t === 'OPERATOR')   return v;
  if (t === 'SYMBOL')     return v;
  if (t === 'KEYWORD')    return v.toUpperCase();
  
  return v || t;
}

export default function TokenPanel({ tokens }) {
  return (
    <div className="panel">
      <div className="panel-header">
        <span className="panel-title">Token Stream</span>
        <span className="panel-count">
          {tokens.length > 0 ? `${tokens.length} tokens` : ''}
        </span>
      </div>

      <div className="panel-body" style={{ padding: 0 }}>
        {tokens.length === 0 ? (
          <div className="token-empty">
            Run code to see the token stream…
          </div>
        ) : (
          <div className="token-grid">
            {tokens.map((tok, i) => {
              const cls = getTokenClass(tok.type);
              return (
                <span
                  key={i}
                  className={`token-badge token-${cls}`}
                  title={`${tok.type}: ${tok.value ?? ''}`}
                >
                  {getTokenLabel(tok)}
                </span>
              );
            })}
          </div>
        )}
      </div>
    </div>
  );
}
