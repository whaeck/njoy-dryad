#ifndef NJOY_DRYAD_PYTHON_DEFINITIONS
#define NJOY_DRYAD_PYTHON_DEFINITIONS

// system includes
#include <complex>

// other includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "dryad/type-aliases.hpp"

namespace python = pybind11;

/**
 *  @brief Add standard comparison definitions
 *
 *  This adds the following standard properties:
 *    - operator==
 *    - operator!=
 *    - operator<
 *    - operator>
 *    - operator<=
 *    - operator>=
 *
 *  @param[in] component   the component to which the definitions have to be added
 */
template < typename Component, typename PythonClass >
void addStandardComparisonDefinitions( PythonClass& component ) {

  component
  .def( python::self == python::self )
  .def( python::self != python::self )
  .def( python::self > python::self )
  .def( python::self < python::self )
  .def( python::self >= python::self )
  .def( python::self <= python::self );
}

/**
 *  @brief Add standard tabulated data definitions
 *
 *  This adds the following standard properties:
 *    - lower_energy_limit
 *    - upper_energy_limit
 *    - call operator
 *    - linearise
 *    - boundaries, interpolants
 *    - number_points, number_regions
 *    - is_linearised
 *    - arithmetic operators
 *
 *  @param[in] table   the table to which the definitions have to be added
 */
template < typename Component, typename PythonClass >
void addStandardTabulatedDefinitions( PythonClass& table ) {

  // type aliases
  using ToleranceConvergence = njoy::dryad::ToleranceConvergence;

  table
  .def(

    "linearise",
    &Component::linearise,
    python::arg( "tolerance" ) = ToleranceConvergence(),
    "Linearise the table\n\n"
    "Arguments:\n"
    "    self        the table\n"
    "    tolerance   the linearisation tolerance"
  )
  .def_property_readonly(

    "boundaries",
    [] ( const Component& self ) -> decltype(auto)
       { return self.boundaries(); },
    "The boundaries of the interpolation regions"
  )
  .def_property_readonly(

    "interpolants",
    [] ( const Component& self ) -> decltype(auto)
       { return self.interpolants(); },
    "The interpolation types of the interpolation regions"
  )
  .def_property_readonly(

    "number_points",
    [] ( const Component& self ) -> decltype(auto)
       { return self.numberPoints(); },
    "The number of points in the table"
  )
  .def_property_readonly(

    "number_regions",
    [] ( const Component& self ) -> decltype(auto)
       { return self.numberRegions(); },
    "The number of interpolation regions in the table"
  )
  .def_property_readonly(

    "is_linearised",
    [] ( const Component& self ) -> decltype(auto)
       { return self.isLinearised(); },
    "Flag indicating whether or not the table is linearised"
  )
  .def( -python::self )
  .def( python::self + double() )
  .def( python::self - double() )
  .def( python::self * double() )
  .def( python::self / double() )
  .def( python::self + python::self )
  .def( python::self - python::self )
  .def( python::self += double() )
  .def( python::self -= double() )
  .def( python::self *= double() )
  .def( python::self /= double() )
  .def( python::self += python::self )
  .def( python::self -= python::self )
  .def( double() + python::self )
  .def( double() - python::self )
  .def( double() * python::self );
}

#endif
