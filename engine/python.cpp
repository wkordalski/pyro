#include <boost/python.hpp>
#include "engine.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(pyro)
{
  class_<pyro::engine>("engine")
    .def("version", &pyro::engine::version)
		.def("run", &pyro::engine::run)
   ;
}
