module type T = {
  [@react.component]
  let make: (~message: string) => React.element;
};

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  /* make sure your component is a default export! */
  let make =
    ReLoadable.lazy_(() => DynamicImport.import("@monorepo-reason-app/a-component"));
};