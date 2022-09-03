# Harpia Game Engine

[![tests](https://github.com/ricardobusta/harpia-game-engine/actions/workflows/tests.yml/badge.svg)](https://github.com/ricardobusta/harpia-game-engine/actions/workflows/tests.yml)

Game Engine made with learning purposes. My idea is to train my knowledge with C++ language and different aspects of engine/ development.

The original engine was started around 2008, with the name of `RGine`, being uploaded to Google Code in 2011 and migrated to Github in 2015. In 2022 I decided to give it another try and see how far I can get.

-- Ricardo Bustamante (aka Busta)

# Configuration

## Checking out

Important to run:
```
git submodule update --init --recursive
```
to make sure all SDL submodules were checked out.

## Upgrading Dependencies

### GLEW

Glew do not work out of the box. First I added the source.
This also required installing a bunch of other tools within it, like git and python.
Then, using msys2 I generated the necessary code with:

```bash
cd auto
make
cd ../
make
make install
make install.all
```

I also removed the `include` directory from `.gitignore`, so it would get added to the git repo.

# Useful Links

## Google Test
- https://google.github.io/googletest/primer.html
- 

## EMScripten
For compiling the project into a web application
https://emscripten.org/docs/introducing_emscripten/about_emscripten.html

## Lazy Foo'
Good old SDL tutorials
https://lazyfoo.net/tutorials/SDL/index.php

## Math libs
- https://github.com/sgorsten/linalg/blob/main/linalg.h
- https://github.com/g-truc/glm

##
- CMake https://cristianadam.eu/20191222/using-github-actions-with-c-plus-plus-and-cmake/