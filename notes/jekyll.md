- `jekyll build`: builds a project
- `jekyll serve`: creates server (default at localhost:4000)
## liquid

jekyll uses liquid: a templating laguage comprising **objects, tags and filters**

> For example, `{{ page.title }}` displays the `page.title` variable.

> To make Jekyll process your changes, add [front matter](https://jekyllrb.com/docs/step-by-step/03-front-matter/) to the top of the page:

```
---
---
```

**Tags:**

``` jekyll
{% if page.show_sidebar %}
  <div class="sidebar">
    sidebar content
  </div>
{% endif %}
```

[List of Liquid Tags](https://jekyllrb.com/docs/liquid/tags/)
[Liquid Filters](https://jekyllrb.com/docs/liquid/filters/)

## front matter

Front matter is a snippet of [YAML](http://yaml.org/) placed between two triple-dashed lines at the start of a file.

You can use front matter to set variables for the page:

```
---
my_number: 5
---
```

## layouts

- create folder `_layouts` manually

> To make `index.html` use your new layout, set the `layout` variable in the front matter. The file should look like this:

```
---
layout: default
title: Home
---
<h1>{{ "Hello World!" | downcase }}</h1>
```