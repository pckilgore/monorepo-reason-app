module.exports = {
  plugins: [
    "@babel/plugin-syntax-dynamic-import",
    "@babel/proposal-class-properties",
    [
      "styled-components",
      {
        fileName: false,
        pure: true
      }
    ]
  ],
  presets: ["@babel/preset-env", "@babel/preset-react"],
  sourceMaps: true
};
