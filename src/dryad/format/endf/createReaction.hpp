#ifndef NJOY_DRYAD_FORMAT_ENDF_REACTION
#define NJOY_DRYAD_FORMAT_ENDF_REACTION

// system includes
#include <vector>

// other includes
#include "tools/Log.hpp"
#include "dryad/format/endf/createTabulatedCrossSection.hpp"
#include "dryad/Reaction.hpp"
#include "ENDFtk/Material.hpp"
#include "ENDFtk/tree/Material.hpp"

namespace njoy {
namespace dryad {
namespace format {
namespace endf {

  /**
   *  @brief Create a Reaction from an unparsed ENDF material
   */
  Reaction createReaction( const ENDFtk::tree::Material& material, int mt ) {

    if ( material.hasSection( 3, mt ) ) {

      auto section = material.section( 3, mt ).parse< 3 >();

      ReactionID id = std::to_string( mt );
      ReactionType type = ReactionType::Primary;
      std::optional< double > mass_q = std::nullopt;
      std::optional< double > reaction_q = std::nullopt;
      if ( type == ReactionType::Primary ) {

        mass_q = section.massDifferenceQValue();
        reaction_q = section.reactionQValue();
      }
      TabulatedCrossSection xs = createTabulatedCrossSection( section );

      return Reaction( std::move( id ), std::move( type ), std::move( xs ),
                       std::move( mass_q ), std::move( reaction_q ) );
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
