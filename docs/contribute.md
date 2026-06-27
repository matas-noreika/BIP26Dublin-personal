---
title: Contribute
description: Information on how people can contribute to site.
icon: fontawesome/solid/people-group
subtitle: Help make this site special❤️!!
---

# Contribute

You can help to make the STMP and this site better by contributing material.
The following sections will describe how the GitHub repository works and
what are the rules to contributing.

## General Overview File Structure

The site is generated using a tool called [mkdocs-material](https://squidfunk.github.io/mkdocs-material/).
All the sites data and build information is found in the `docs/` directory.
Here is a tree diagram of the folders found within the `docs/`:

``` bash title="Site File Structure"
docs
├── blog # (1)
│   ├──index.md # (2)
│   └── posts # (3)
├── index.md # Site Home page
├── sensors # Directory that holds all sensor tutorials and information
│   ├── bmp280
│   ├── index.md
│   ├── lc29h
│   └── qmi8658c
└── setup # Directory that holds all setup tutorials and information
```

1. This is the blog directory that holds all the files needed by the blog to work😊
2. This is the blog index page where everything is organised by dates and categories
3. This is the posts directory, you will be adding your own posts here by
   making a new file

## Adding a Post

Adding a post is as simple as adding a new file to the `docs/blog/posts/` directory.
Each post is a markdown file and follows markdown file structure.
The difference in some of these markdown files is some metadata to tell details
about the post like author and date create.

Here is a sample of that metadata also referred to as front-matter:

``` yaml title="Sample of metadata options for blog post"
---
date:
  created: 2026-06-27 # date created **required**
  updated: 2026-06-27 # date updated last
draft: false # set to true if you wish for post to not appear on site
author:
  - Matas # name defined in site configuration (added by request)
readtime: 5 # time in minutes
pin: false # Pins the post on blog index page
links: # Custom navigation for post to link other content
  - Home: index.md
  - Blog Index: blog/index.md
---
```

??? note "Author Notice"
  To be added as an author please send a request by posting an issue on the
  github repository.

## Adding Author Page

**TBD**
