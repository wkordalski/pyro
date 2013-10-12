from distutils.core import setup
from distutils.extension import Extension

setup(
  name = "Pyro",
  ext_modules=[
    Extension("pyro", ['engine/engine.cpp', 'engine/renderer.cpp', 'engine/python.cpp'],
	      libraries = ['boost_python3', 'sfml-window'],
	      extra_compile_args = ['-std=c++11'])
    ]
    )

