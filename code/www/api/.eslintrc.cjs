module.exports = {
  extends: [
    "eslint:recommended",
    "plugin:@typescript-eslint/recommended",
    "plugin:@typescript-eslint/recommended-requiring-type-checking",
    "prettier",
  ],
  plugins: ["@typescript-eslint"],
  parser: "@typescript-eslint/parser",
  parserOptions: {
    ecmaVersion: "latest",
    sourceType: "module",
    project: true,
    tsconfigRootDir: __dirname,
  },
  root: true,
  rules: {
    eqeqeq: "error",
    curly: "error",
    "no-console": "off",
    semi: ["error", "always"],
    quotes: ["error", "double"],
    "plugin1/rule1": "off",
    "@typescript-eslint/no-unsafe-member-access": "off",
    "@typescript-eslint/no-unsafe-return": "off",
    "@typescript-eslint/no-this-alias": "off",
    "@typescript-eslint/no-explicit-any": "off",
  },
};

// off for set off rule
// warn for set just warn
// error for set error code
