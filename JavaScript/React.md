- React is a modular, scalable, flexible, and popular front-end framework.
- used for [[Next.js]]

- uses [JSX](https://www.codecademy.com/resources/docs/react/jsx)
> JSX is a syntax extension of JavaScript that combines the JavaScript and HTML-like syntax to provide highly functional, reusable markup. It’s used to create DOM elements which are then rendered in the React DOM.

`const headerElement = <h1>This is a header</h1>;`

> JSX must have exactly one outer element, and other elements can be nested inside.
## basic functionality:

``` JS
import React from 'react';
import { createRoot } from 'react-dom/client';

const container = document.getElementById('app');
const root = createRoot(container);
root.render(<h1>Hello world</h1>);
```

>`createRoot()` from `react-dom/client` can be used to create a React root at the specified DOM element.
>A React root’s `render()` method can be used to render JSX on the screen.
>A React root’s `render()` method only updates DOM elements that have changed using the virtual DOM.
## more

- **The Virtual DOM**: One special thing about a React root’s `render()` method is that it _only updates DOM elements that have changed_. That means that if you render the exact same thing twice in a row, the second render will do nothing.