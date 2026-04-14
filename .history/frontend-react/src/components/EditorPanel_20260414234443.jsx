import Editor from "@monaco-editor/react";
import { useState, useEffect } from "react";

const DEFAULT_CODE = "";

export default function EditorPanel({
  code,
  onChange,
  onRun,
  loading,
  status,
}) {
  const [editorTheme, setEditorTheme] = useState("minilang-dark");

  useEffect(() => {
    const updateTheme = () => {
      const siteTheme = document.documentElement.getAttribute("data-theme");
      setEditorTheme(
        siteTheme === "light" ? "minilang-light" : "minilang-dark",
      );
    };
    updateTheme();
    const observer = new MutationObserver(updateTheme);
    observer.observe(document.documentElement, {
      attributes: true,
      attributeFilter: ["data-theme"],
    });
    return () => observer.disconnect();
  }, []);
  const handleEditorWillMount = (monaco) => {
    // Register a new language
    monaco.languages.register({ id: "minilang" });

    // Register a tokens provider for the language
    monaco.languages.setMonarchTokensProvider("minilang", {
      keywords: [
        "let",
        "if",
        "else",
        "while",
        "for",
        "print",
        "printf",
        "return",
        "fn",
        "true",
        "false",
        "type",
      ],
      operators: [
        "=",
        ">",
        "<",
        "!",
        "~",
        "?",
        ":",
        "==",
        "<=",
        ">=",
        "!=",
        "&&",
        "||",
        "++",
        "--",
        "+",
        "-",
        "*",
        "/",
        "&",
        "|",
        "^",
        "%",
        "<<",
        ">>",
        ">>>",
        "+=",
        "-=",
        "*=",
        "/=",
        "&=",
        "|=",
        "^=",
        "%=",
        "<<=",
        ">>=",
        ">>>=",
      ],
      symbols: /[=><!~?:&|+\-*\/\^%]+/,
      tokenizer: {
        root: [
          [
            /[a-z_$][\w$]*/,
            {
              cases: {
                "@keywords": "keyword",
                "@default": "identifier",
              },
            },
          ],
          { include: "@whitespace" },
          [/[{}()\[\]]/, "@brackets"],
          [/[<>](?!@symbols)/, "@brackets"],
          [
            /@symbols/,
            {
              cases: {
                "@operators": "operator",
                "@default": "",
              },
            },
          ],
          [/\d*\.\d+([eE][\-+]?\d+)?/, "number.float"],
          [/\d+/, "number"],
          [/[;,.]/, "delimiter"],
          [/"([^"\\]|\\.)*$/, "string.invalid"],
          [/"/, { token: "string.quote", bracket: "@open", next: "@string" }],
        ],
        string: [
          [/[^\\"]+/, "string"],
          [/\\./, "string.escape"],
          [/"/, { token: "string.quote", bracket: "@close", next: "@pop" }],
        ],
        whitespace: [
          [/[ \t\r\n]+/, "white"],
          [/\/\*/, "comment", "@comment"],
          [/\/\/.*$/, "comment"],
        ],
        comment: [
          [/[^\/*]+/, "comment"],
          [/\/\*/, "comment", "@push"],
          ["\\*/", "comment", "@pop"],
          [/[\/*]/, "comment"],
        ],
      },
    });

    // Define all themes
    monaco.editor.defineTheme("minilang-dark", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "e8a020", fontStyle: "bold" },
        { token: "identifier", foreground: "4ecdc4" },
        { token: "number", foreground: "e8a020" },
        { token: "string", foreground: "4ade80" },
        { token: "comment", foreground: "4a5568", fontStyle: "italic" },
        { token: "operator", foreground: "f87171" },
      ],
      colors: {
        "editor.background": "#1a1d27",
        "editorCursor.foreground": "#e8a020",
        "editor.lineHighlightBackground": "#1e2130",
        "editorLineNumber.foreground": "#4a5568",
        "editorLineNumber.activeForeground": "#8892b0",
      },
    });

    monaco.editor.defineTheme("minilang-light", {
      base: "vs",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "0066cc", fontStyle: "bold" },
        { token: "identifier", foreground: "333333" },
        { token: "number", foreground: "0066cc" },
        { token: "string", foreground: "008800" },
        { token: "comment", foreground: "999999", fontStyle: "italic" },
        { token: "operator", foreground: "cc0000" },
      ],
      colors: {
        "editor.background": "#ffffff",
        "editorCursor.foreground": "#0066cc",
        "editor.lineHighlightBackground": "#f0f4f8",
        "editorLineNumber.foreground": "#999999",
        "editorLineNumber.activeForeground": "#333333",
      },
    });

    monaco.editor.defineTheme("minilang-monokai", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "f92672", fontStyle: "bold" },
        { token: "identifier", foreground: "f8f8f2" },
        { token: "number", foreground: "ae81ff" },
        { token: "string", foreground: "e6db74" },
        { token: "comment", foreground: "75715e", fontStyle: "italic" },
        { token: "operator", foreground: "f92672" },
      ],
      colors: {
        "editor.background": "#272822",
        "editorCursor.foreground": "#f8f8f0",
        "editor.lineHighlightBackground": "#3e3d32",
        "editorLineNumber.foreground": "#75715e",
        "editorLineNumber.activeForeground": "#f8f8f0",
      },
    });

    monaco.editor.defineTheme("minilang-nord", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "81a1c1", fontStyle: "bold" },
        { token: "identifier", foreground: "d8dee9" },
        { token: "number", foreground: "a3be8c" },
        { token: "string", foreground: "a3be8c" },
        { token: "comment", foreground: "616e88", fontStyle: "italic" },
        { token: "operator", foreground: "81a1c1" },
      ],
      colors: {
        "editor.background": "#2e3440",
        "editorCursor.foreground": "#d8dee9",
        "editor.lineHighlightBackground": "#3b4252",
        "editorLineNumber.foreground": "#4c566a",
        "editorLineNumber.activeForeground": "#d8dee9",
      },
    });
  };

  const handleKeyDown = (e) => {
    if ((e.ctrlKey || e.metaKey) && e.key === "Enter") {
      e.preventDefault();
      onRun();
    }
  };

  const dotClass =
    status === "ok"
      ? "ok"
      : status === "error"
        ? "err"
        : status === "loading"
          ? "loading"
          : "idle";
  const statusMsg =
    status === "ok"
      ? "Compilation successful"
      : status === "error"
        ? "Compilation failed"
        : status === "loading"
          ? "Compiling…"
          : "Ready — write code and press RUN";

  return (
    <div className="panel" onKeyDown={handleKeyDown}>
      <div className="panel-header">
        <span className="panel-title">Source Code</span>
        <span
          className="panel-count"
          style={{ fontSize: "11px", color: "var(--text-muted)" }}
        >
          Ctrl+Enter to run
        </span>
      </div>

      <div className="editor-wrapper">
        <Editor
          height="100%"
          language="minilang"
          value={code}
          onChange={(val) => onChange(val ?? "")}
          beforeMount={handleEditorWillMount}
          theme={editorTheme}
          options={{
            fontSize: 14,
            fontFamily: "'JetBrains Mono', 'Fira Code', monospace",
            fontLigatures: true,
            minimap: { enabled: false },
            lineNumbers: "on",
            scrollBeyondLastLine: false,
            automaticLayout: true,
            padding: { top: 16, bottom: 16 },
            scrollbar: { verticalScrollbarSize: 6, horizontalScrollbarSize: 6 },
            overviewRulerLanes: 0,
            renderLineHighlight: "all",
            cursorBlinking: "smooth",
            smoothScrolling: true,
            tabSize: 2,
            wordWrap: "off",
            contextmenu: false,
          }}
        />
      </div>

      <div className="run-bar">
        <button
          id="btn-run"
          className="btn-run"
          onClick={onRun}
          disabled={loading}
        >
          <span className="btn-run-icon">▶</span>
          RUN
        </button>
      </div>

      <div className="status-bar">
        <div className={`status-dot ${dotClass}`} />
        <span className="status-msg">{statusMsg}</span>
      </div>
    </div>
  );
}
