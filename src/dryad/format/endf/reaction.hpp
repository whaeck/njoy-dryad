#ifndef NJOY_DRYAD_FORMAT_ENDF_REACTION
#define NJOY_DRYAD_FORMAT_ENDF_REACTION

// system includes
#include <vector>

// other includes
#include "tools/Log.hpp"
#include "tools/std20/ranges.hpp"
#include "dryad/format/endf/tabulatedCrossSection.hpp"
#include "dryad/Reaction.hpp"
#include "ENDFtk/Material.hpp"
#include "ENDFtk/tree/Material.hpp"

namespace njoy {
namespace dryad {
namespace format {
namespace endf {

  /**
   *  @brief Create a Reaction from an ENDF material
   */
  Reaction reaction( const ENDFtk::tree::Material& material, int mt ) {

    if ( material.hasSection( 3, mt ) ) {

      auto section = material.section( 3, mt ).parse< 3 >();

      ReactionID id = std::to_string( mt );
      double mass_q = section.massDifferenceQValue();
      double reaction_q = section.reactionQValue();
      TabulatedCrossSection xs = tabulatedCrossSection( section );

      return Reaction( std::move( id ), mass_q, reaction_q, std::move( xs ) );
    }
    else {

      Log::error( "ENDF material does not have reaction data for MT{}", mt );
      throw std::exception();
    }
  }

} // endf namespace
} // format namespace
} // dryad namespace
} // njoy namespace

#endif
