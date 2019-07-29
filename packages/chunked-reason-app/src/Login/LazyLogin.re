module type T = {
  [@react.component]
  let make: _ => React.element;
};

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  let make = ReLoadable.lazy_(() => DynamicImport.import("./Login.bs.js"));
};
