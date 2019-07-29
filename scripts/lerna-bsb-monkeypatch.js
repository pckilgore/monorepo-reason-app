#!/usr/bin/env node

const replace = require("replace");

const patchRegex = /\[\"ignore\",/;
const replacement = `["inherit",`;

let replaced = 0;

// Listen to replace's side effects because replace isn't that great...
const log = console.log;
console.log = function patchedLog(...msgs) {
  log(...msgs);
  replaced = true;
};

log("POST-INSTALL::Monkeypatching lerna....");
replace({
  regex: patchRegex,
  replacement,
  paths: ["./node_modules/@lerna/child-process/index.js"]
});
replaced ? log("...done") : log("...nothing to do?");

// Probably not necessary but...
console.log = log;
