# Bootstrapper Application

### What's this?

This package is a [create-react-app](https://facebook.github.io/create-react-app/docs/getting-started) bootstrapper for our reason app.

### Why is this?

Getting code splitting, hot reloading, and developer experience right for react apps is a pain in the butt except for the most machoistic of developers.  So rather than try to recreate what CRA has done, its easier to just use it.

### How do I use this project

See the `chunked-reason-app` directory for an example of a package that exports a react app with code splitting.  Mount that app to the DOM with this app in the `src/index.js` directory.  You are done.

```jsx
// src/index.js

/* stuff... */

import ReasonApp from '@monorepo-reason-app/reason-react-chunked';
ReactDOM.render(<ReasonApp />, document.getElementById('root'));

/* ...more stuff */
```