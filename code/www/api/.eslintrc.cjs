module.exports = {
  extends: [
    'eslint:recommended',
    'plugin:@typescript-eslint/recommended',
    'plugin:@typescript-eslint/recommended-requiring-type-checking',
  ],
  plugins: ['@typescript-eslint'],
  parser: '@typescript-eslint/parser',
  parserOptions: {
    project: true,
    tsconfigRootDir: __dirname,
  },
  "rules": {
        "eqeqeq": "warn",
        "curly": "warn",
        "no-console": "error",
        "quotes": ["warn", "double"],
        "plugin1/rule1": "warn"
  }
  root: true,
};

// off for set off rule
// warn for set just warn
// error for set error code