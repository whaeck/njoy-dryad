void verifyNeutronTotalReaction( const Reaction& total ) {

  CHECK( id::ReactionID( "1" ) == total.identifier() );
  CHECK( ReactionType::Summation == total.type() );
  CHECK( false == total.hasProducts() );
  CHECK( false == total.isLinearised() );

  CHECK( std::nullopt != total.partialReactionIdentifiers() );
  auto partials = total.partialReactionIdentifiers().value();
//  CHECK( 2 == partials.size() );
//  CHECK( id::ReactionID( "2" ) == partials[0] );
//  CHECK( id::ReactionID( "102" ) == partials[1] );

  CHECK( std::nullopt == total.massDifferenceQValue() );
  CHECK( std::nullopt == total.reactionQValue() );

  CHECK( false == total.crossSection().isLinearised() );
  CHECK( 153 == total.crossSection().numberPoints() );
  CHECK( 2 == total.crossSection().numberRegions() );
  CHECK( 153 == total.crossSection().energies().size() );
  CHECK( 153 == total.crossSection().values().size() );
  CHECK( 2 == total.crossSection().boundaries().size() );
  CHECK( 2 == total.crossSection().interpolants().size() );
  CHECK( 8 == total.crossSection().boundaries()[0] );
  CHECK( 152 == total.crossSection().boundaries()[1] );
  CHECK( InterpolationType::LogLog == total.crossSection().interpolants()[0] );
  CHECK( InterpolationType::LinearLinear == total.crossSection().interpolants()[1] );
  CHECK_THAT( 1e-5, WithinRel( total.crossSection().energies()[0] ) );
  CHECK_THAT( 5e-3, WithinRel( total.crossSection().energies()[8] ) );
  CHECK_THAT( 2e+7, WithinRel( total.crossSection().energies()[152] ) );
  CHECK_THAT( 3.716477e+1, WithinRel( total.crossSection().values()[0] ) );
  CHECK_THAT( 2.118421e+1, WithinRel( total.crossSection().values()[8] ) );
  CHECK_THAT( 4.818679e-1, WithinRel( total.crossSection().values()[152] ) );

  CHECK( 0 == total.products().size() );
}

void verifyNeutronElasticReaction( const Reaction& elastic ) {

  CHECK( id::ReactionID( "2" ) == elastic.identifier() );
  CHECK( ReactionType::Primary == elastic.type() );
  CHECK( false == elastic.hasProducts() );
  CHECK( true == elastic.isLinearised() );

  CHECK( std::nullopt != elastic.massDifferenceQValue() );
  CHECK( std::nullopt != elastic.reactionQValue() );
  CHECK_THAT( 0, WithinRel( elastic.massDifferenceQValue().value() ) );
  CHECK_THAT( 0, WithinRel( elastic.reactionQValue().value() ) );

  CHECK( true == elastic.crossSection().isLinearised() );
  CHECK( 153 == elastic.crossSection().numberPoints() );
  CHECK( 1 == elastic.crossSection().numberRegions() );
  CHECK( 153 == elastic.crossSection().energies().size() );
  CHECK( 153 == elastic.crossSection().values().size() );
  CHECK( 1 == elastic.crossSection().boundaries().size() );
  CHECK( 1 == elastic.crossSection().interpolants().size() );
  CHECK( 152 == elastic.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == elastic.crossSection().interpolants()[0] );
  CHECK_THAT( 1e-5, WithinRel( elastic.crossSection().energies()[0] ) );
  CHECK_THAT( 2e+7, WithinRel( elastic.crossSection().energies()[152] ) );
  CHECK_THAT( 2.043608e+1, WithinRel( elastic.crossSection().values()[0] ) );
  CHECK_THAT( 4.818408e-1, WithinRel( elastic.crossSection().values()[152] ) );

  CHECK( 0 == elastic.products().size() );
}

void verifyNeutronCaptureReaction( const Reaction& capture ) {

  CHECK( id::ReactionID( "102" ) == capture.identifier() );
  CHECK( ReactionType::Primary == capture.type() );
  CHECK( true == capture.hasProducts() );
  CHECK( false == capture.isLinearised() );

  CHECK( std::nullopt != capture.massDifferenceQValue() );
  CHECK( std::nullopt != capture.reactionQValue() );
  CHECK_THAT( 2.224648e+6, WithinRel( capture.massDifferenceQValue().value() ) );
  CHECK_THAT( 2.224648e+6, WithinRel( capture.reactionQValue().value() ) );

  CHECK( false == capture.crossSection().isLinearised() );
  CHECK( 153 == capture.crossSection().numberPoints() );
  CHECK( 2 == capture.crossSection().numberRegions() );
  CHECK( 153 == capture.crossSection().energies().size() );
  CHECK( 153 == capture.crossSection().values().size() );
  CHECK( 2 == capture.crossSection().boundaries().size() );
  CHECK( 2 == capture.crossSection().interpolants().size() );
  CHECK( 32 == capture.crossSection().boundaries()[0] );
  CHECK( 152 == capture.crossSection().boundaries()[1] );
  CHECK( InterpolationType::LogLog == capture.crossSection().interpolants()[0] );
  CHECK( InterpolationType::LinearLinear == capture.crossSection().interpolants()[1] );
  CHECK_THAT( 1e-5, WithinRel( capture.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+4, WithinRel( capture.crossSection().energies()[32] ) );
  CHECK_THAT( 2e+7, WithinRel( capture.crossSection().energies()[152] ) );
  CHECK_THAT( 1.672869e+1, WithinRel( capture.crossSection().values()[0] ) );
  CHECK_THAT( 4.950573e-4, WithinRel( capture.crossSection().values()[32] ) );
  CHECK_THAT( 2.710792e-5, WithinRel( capture.crossSection().values()[152] ) );

  CHECK( 2 == capture.products().size() );
  auto gamma = capture.products()[0];
  CHECK( id::ParticleID( "g" ) == gamma.identifier() );
  auto deuterium = capture.products()[1];
  CHECK( id::ParticleID( "d" ) == deuterium.identifier() );
}

void verifyElectronTotalReaction( const Reaction& total ) {

  CHECK( id::ReactionID( "501" ) == total.identifier() );
  CHECK( ReactionType::Summation == total.type() );
  CHECK( false == total.hasProducts() );
  CHECK( true == total.isLinearised() );

  CHECK( std::nullopt != total.partialReactionIdentifiers() );
  auto partials = total.partialReactionIdentifiers().value();
  CHECK( 5 == partials.size() );
  CHECK( id::ReactionID(  "525" ) == partials[0] );
  CHECK( id::ReactionID( "-526" ) == partials[1] );
  CHECK( id::ReactionID(  "527" ) == partials[2] );
  CHECK( id::ReactionID(  "528" ) == partials[3] );
  CHECK( id::ReactionID(  "534" ) == partials[4] );

  CHECK( std::nullopt == total.massDifferenceQValue() );
  CHECK( std::nullopt == total.reactionQValue() );

  CHECK( true == total.crossSection().isLinearised() );
  CHECK( 349 == total.crossSection().numberPoints() );
  CHECK( 1 == total.crossSection().numberRegions() );
  CHECK( 349 == total.crossSection().energies().size() );
  CHECK( 349 == total.crossSection().values().size() );
  CHECK( 1 == total.crossSection().boundaries().size() );
  CHECK( 1 == total.crossSection().interpolants().size() );
  CHECK( 348 == total.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == total.crossSection().interpolants()[0] );
  CHECK_THAT( 10., WithinRel( total.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( total.crossSection().energies()[348] ) );
  CHECK_THAT( 274896030., WithinRel( total.crossSection().values()[0] ) );
  CHECK_THAT( 177322.091, WithinRel( total.crossSection().values()[348] ) );

  CHECK( 0 == total.products().size() );
}

void verifyElectronTotalIonisationReaction( const Reaction& ionisation ) {

  CHECK( id::ReactionID( "522" ) == ionisation.identifier() );
  CHECK( ReactionType::Summation == ionisation.type() );
  CHECK( false == ionisation.hasProducts() );
  CHECK( true == ionisation.isLinearised() );

  CHECK( std::nullopt != ionisation.partialReactionIdentifiers() );
  auto partials = ionisation.partialReactionIdentifiers().value();
  CHECK( 1 == partials.size() );
  CHECK( id::ReactionID( "534" ) == partials[0] );

  CHECK( std::nullopt == ionisation.massDifferenceQValue() );
  CHECK( std::nullopt == ionisation.reactionQValue() );

  CHECK( true == ionisation.crossSection().isLinearised() );
  CHECK( 35 == ionisation.crossSection().numberPoints() );
  CHECK( 1 == ionisation.crossSection().numberRegions() );
  CHECK( 35 == ionisation.crossSection().energies().size() );
  CHECK( 35 == ionisation.crossSection().values().size() );
  CHECK( 1 == ionisation.crossSection().boundaries().size() );
  CHECK( 1 == ionisation.crossSection().interpolants().size() );
  CHECK( 34 == ionisation.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == ionisation.crossSection().interpolants()[0] );
  CHECK_THAT( 13.6, WithinRel( ionisation.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( ionisation.crossSection().energies()[34] ) );
  CHECK_THAT( 0., WithinRel( ionisation.crossSection().values()[0] ) );
  CHECK_THAT( 82892.4, WithinRel( ionisation.crossSection().values()[34] ) );

  CHECK( 0 == ionisation.products().size() );
}

void verifyElectronElasticReaction( const Reaction& elastic ) {

  CHECK( id::ReactionID( "525" ) == elastic.identifier() );
  CHECK( ReactionType::Primary == elastic.type() );
  CHECK( true == elastic.hasProducts() );
  CHECK( true == elastic.isLinearised() );

  CHECK( std::nullopt == elastic.massDifferenceQValue() );
  CHECK( std::nullopt != elastic.reactionQValue() );
  CHECK_THAT( 0, WithinRel( elastic.reactionQValue().value() ) );

  CHECK( true == elastic.crossSection().isLinearised() );
  CHECK( 101 == elastic.crossSection().numberPoints() );
  CHECK( 1 == elastic.crossSection().numberRegions() );
  CHECK( 101 == elastic.crossSection().energies().size() );
  CHECK( 101 == elastic.crossSection().values().size() );
  CHECK( 1 == elastic.crossSection().boundaries().size() );
  CHECK( 1 == elastic.crossSection().interpolants().size() );
  CHECK( 100 == elastic.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == elastic.crossSection().interpolants()[0] );
  CHECK_THAT( 10., WithinRel( elastic.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( elastic.crossSection().energies()[100] ) );
  CHECK_THAT( 274896000., WithinRel( elastic.crossSection().values()[0] ) );
  CHECK_THAT( 1.31176e-5, WithinRel( elastic.crossSection().values()[100] ) );

  CHECK( 1 == elastic.products().size() );
  auto photon = elastic.products()[0];
  CHECK( id::ParticleID( "e-" ) == photon.identifier() );
  CHECK( true == photon.isLinearised() );
  CHECK( false == photon.hasAverageEnergy() );
  CHECK( true == photon.hasDistributionData() );
  CHECK( true == std::holds_alternative< int >( photon.multiplicity() ) );
  auto multiplicity = std::get< int >( photon.multiplicity() );
  CHECK( 1 == multiplicity );
  CHECK( std::nullopt == photon.averageEnergy() );
  CHECK( std::nullopt != photon.distributionData() );
  CHECK( true == std::holds_alternative< TwoBodyDistributionData >( photon.distributionData().value() ) );
  auto data = std::get< TwoBodyDistributionData >( photon.distributionData().value() );
  CHECK( DistributionDataType::TwoBody == data.type() );
  CHECK( true == std::holds_alternative< TabulatedAngularDistributions >( data.angle() ) );
  auto angle = std::get< TabulatedAngularDistributions >( data.angle() );
  CHECK( 16 == angle.numberPoints() );
  CHECK( 1 == angle.numberRegions() );
  CHECK( 16 == angle.grid().size() );
  CHECK( 16 == angle.distributions().size() );
  CHECK( 1 == angle.boundaries().size() );
  CHECK( 1 == angle.interpolants().size() );
  CHECK_THAT(       10., WithinRel( angle.grid()[0] ) );
  CHECK_THAT(     1000., WithinRel( angle.grid()[1] ) );
  CHECK_THAT( 66250000., WithinRel( angle.grid()[14] ) );
  CHECK_THAT(     1e+11, WithinRel( angle.grid()[15] ) );
  CHECK(  2 == angle.distributions()[0].cosines().size() );
  CHECK(  2 == angle.distributions()[0].values().size() );
  CHECK( 30 == angle.distributions()[1].cosines().size() );
  CHECK( 30 == angle.distributions()[1].values().size() );
  CHECK( 95 == angle.distributions()[14].cosines().size() );
  CHECK( 95 == angle.distributions()[14].values().size() );
  CHECK( 96 == angle.distributions()[15].cosines().size() );
  CHECK( 96 == angle.distributions()[15].values().size() );
  CHECK_THAT( -1.          , WithinRel( angle.distributions()[0].cosines()[0] ) );
  CHECK_THAT(  0.999999    , WithinRel( angle.distributions()[0].cosines()[1] ) );
  CHECK_THAT(  0.5         , WithinRel( angle.distributions()[0].values()[0] ) );
  CHECK_THAT(  0.5         , WithinRel( angle.distributions()[0].values()[1] ) );
  CHECK_THAT( -1.          , WithinRel( angle.distributions()[1].cosines()[0] ) );
  CHECK_THAT( -0.93        , WithinRel( angle.distributions()[1].cosines()[1] ) );
  CHECK_THAT(  0.9962001   , WithinRel( angle.distributions()[1].cosines()[28] ) );
  CHECK_THAT(  0.999999    , WithinRel( angle.distributions()[1].cosines()[29] ) );
  CHECK_THAT(  0.00293923  , WithinRel( angle.distributions()[1].values()[0] ) );
  CHECK_THAT(  0.00314865  , WithinRel( angle.distributions()[1].values()[1] ) );
  CHECK_THAT( 42.358       , WithinRel( angle.distributions()[1].values()[28] ) );
  CHECK_THAT( 62.1102      , WithinRel( angle.distributions()[1].values()[29] ) );
  CHECK_THAT( -1.          , WithinRel( angle.distributions()[14].cosines()[0] ) );
  CHECK_THAT( -0.995       , WithinRel( angle.distributions()[14].cosines()[1] ) );
  CHECK_THAT(  0.9999989   , WithinRel( angle.distributions()[14].cosines()[93] ) );
  CHECK_THAT(  0.999999    , WithinRel( angle.distributions()[14].cosines()[94] ) );
  CHECK_THAT(  1.51157e-11 , WithinRel( angle.distributions()[14].values()[0] ) );
  CHECK_THAT(  6.43040e-10 , WithinRel( angle.distributions()[14].values()[1] ) );
  CHECK_THAT(   8.14179e+5 , WithinRel( angle.distributions()[14].values()[93] ) );
  CHECK_THAT(   9.84753e+5 , WithinRel( angle.distributions()[14].values()[94] ) );
  CHECK_THAT( -1.          , WithinRel( angle.distributions()[15].cosines()[0] ) );
  CHECK_THAT( -0.9999      , WithinRel( angle.distributions()[15].cosines()[1] ) );
  CHECK_THAT(  0.9999989   , WithinRel( angle.distributions()[15].cosines()[94] ) );
  CHECK_THAT(  0.999999    , WithinRel( angle.distributions()[15].cosines()[95] ) );
  CHECK_THAT(  6.25670e-13 , WithinRel( angle.distributions()[15].values()[0] ) );
  CHECK_THAT(  1.25808e-11 , WithinRel( angle.distributions()[15].values()[1] ) );
  CHECK_THAT(   8.15658e+5 , WithinRel( angle.distributions()[15].values()[94] ) );
  CHECK_THAT(   9.86945e+5 , WithinRel( angle.distributions()[15].values()[95] ) );
  CHECK( 15 == angle.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == angle.interpolants()[0] );
}

void verifyElectronTotalElasticReaction( const Reaction& telastic ) {

  CHECK( id::ReactionID( "526" ) == telastic.identifier() );
  CHECK( ReactionType::Summation == telastic.type() );
  CHECK( false == telastic.hasProducts() );
  CHECK( true == telastic.isLinearised() );

  CHECK( std::nullopt != telastic.partialReactionIdentifiers() );
  auto partials = telastic.partialReactionIdentifiers().value();
  CHECK( 2 == partials.size() );
  CHECK( id::ReactionID(  "525" ) == partials[0] );
  CHECK( id::ReactionID( "-526" ) == partials[1] );

  CHECK( std::nullopt == telastic.massDifferenceQValue() );
  CHECK( std::nullopt == telastic.reactionQValue() );

  CHECK( true == telastic.crossSection().isLinearised() );
  CHECK( 101 == telastic.crossSection().numberPoints() );
  CHECK( 1 == telastic.crossSection().numberRegions() );
  CHECK( 101 == telastic.crossSection().energies().size() );
  CHECK( 101 == telastic.crossSection().values().size() );
  CHECK( 1 == telastic.crossSection().boundaries().size() );
  CHECK( 1 == telastic.crossSection().interpolants().size() );
  CHECK( 100 == telastic.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == telastic.crossSection().interpolants()[0] );
  CHECK_THAT( 10., WithinRel( telastic.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( telastic.crossSection().energies()[100] ) );
  CHECK_THAT( 274896000., WithinRel( telastic.crossSection().values()[0] ) );
  CHECK_THAT( 12987.1, WithinRel( telastic.crossSection().values()[100] ) );

  CHECK( 0 == telastic.products().size() );
}

void verifyElectronBremsstrahlungReaction( const Reaction& bremsstrahlung ) {

  CHECK( id::ReactionID( "527" ) == bremsstrahlung.identifier() );
  CHECK( ReactionType::Primary == bremsstrahlung.type() );
  CHECK( true == bremsstrahlung.hasProducts() );
  CHECK( true == bremsstrahlung.isLinearised() );

  CHECK( std::nullopt == bremsstrahlung.massDifferenceQValue() );
  CHECK( std::nullopt != bremsstrahlung.reactionQValue() );
  CHECK_THAT( 0, WithinRel( bremsstrahlung.reactionQValue().value() ) );

  CHECK( true == bremsstrahlung.crossSection().isLinearised() );
  CHECK( 96 == bremsstrahlung.crossSection().numberPoints() );
  CHECK( 1 == bremsstrahlung.crossSection().numberRegions() );
  CHECK( 96 == bremsstrahlung.crossSection().energies().size() );
  CHECK( 96 == bremsstrahlung.crossSection().values().size() );
  CHECK( 1 == bremsstrahlung.crossSection().boundaries().size() );
  CHECK( 1 == bremsstrahlung.crossSection().interpolants().size() );
  CHECK( 95 == bremsstrahlung.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == bremsstrahlung.crossSection().interpolants()[0] );
  CHECK_THAT( 10., WithinRel( bremsstrahlung.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( bremsstrahlung.crossSection().energies()[95] ) );
  CHECK_THAT( 29.7832 , WithinRel( bremsstrahlung.crossSection().values()[0] ) );
  CHECK_THAT( 0.990621, WithinRel( bremsstrahlung.crossSection().values()[95] ) );

  CHECK( 2 == bremsstrahlung.products().size() );
  auto gamma = bremsstrahlung.products()[0];
  CHECK( id::ParticleID( "g" ) == gamma.identifier() );
  CHECK( true == gamma.isLinearised() );
  CHECK( false == gamma.hasAverageEnergy() );
  CHECK( true == gamma.hasDistributionData() );
  CHECK( true == std::holds_alternative< int >( gamma.multiplicity() ) );
  auto multiplicity = std::get< int >( gamma.multiplicity() );
  CHECK( 1 == multiplicity );
  CHECK( std::nullopt == gamma.averageEnergy() );
  CHECK( std::nullopt != gamma.distributionData() );
  CHECK( true == std::holds_alternative< UncorrelatedDistributionData >( gamma.distributionData().value() ) );
  auto data = std::get< UncorrelatedDistributionData >( gamma.distributionData().value() );
  CHECK( DistributionDataType::Uncorrelated == data.type() );
  CHECK( true == std::holds_alternative< IsotropicAngularDistributions >( data.angle() ) );
  CHECK( true == std::holds_alternative< TabulatedEnergyDistributions >( data.energy() ) );
  auto energy = std::get< TabulatedEnergyDistributions >( data.energy() );
  CHECK( 10 == energy.numberPoints() );
  CHECK( 1 == energy.numberRegions() );
  CHECK( 10 == energy.grid().size() );
  CHECK( 10 == energy.distributions().size() );
  CHECK( 1 == energy.boundaries().size() );
  CHECK( 1 == energy.interpolants().size() );
  CHECK_THAT(   10.   , WithinRel( energy.grid()[0] ) );
  CHECK_THAT(   20.736, WithinRel( energy.grid()[1] ) );
  CHECK_THAT(   1e+7  , WithinRel( energy.grid()[8] ) );
  CHECK_THAT(   1e+11 , WithinRel( energy.grid()[9] ) );
  CHECK(  17 == energy.distributions()[0].energies().size() );
  CHECK(  17 == energy.distributions()[0].values().size() );
  CHECK(  19 == energy.distributions()[1].energies().size() );
  CHECK(  19 == energy.distributions()[1].values().size() );
  CHECK(  85 == energy.distributions()[8].energies().size() );
  CHECK(  85 == energy.distributions()[8].values().size() );
  CHECK( 111 == energy.distributions()[9].energies().size() );
  CHECK( 111 == energy.distributions()[9].values().size() );
  CHECK_THAT(  0.1       , WithinRel( energy.distributions()[0].energies()[0] ) );
  CHECK_THAT(  0.133352  , WithinRel( energy.distributions()[0].energies()[1] ) );
  CHECK_THAT(  9.9       , WithinRel( energy.distributions()[0].energies()[15] ) );
  CHECK_THAT( 10.        , WithinRel( energy.distributions()[0].energies()[16] ) );
  CHECK_THAT( 2.1394     , WithinRel( energy.distributions()[0].values()[0] ) );
  CHECK_THAT( 1.60421    , WithinRel( energy.distributions()[0].values()[1] ) );
  CHECK_THAT(  .0214392  , WithinRel( energy.distributions()[0].values()[15] ) );
  CHECK_THAT(  .0212245  , WithinRel( energy.distributions()[0].values()[16] ) );
  CHECK_THAT(  0.1       , WithinRel( energy.distributions()[1].energies()[0] ) );
  CHECK_THAT(  0.14608   , WithinRel( energy.distributions()[1].energies()[1] ) );
  CHECK_THAT( 20.5286    , WithinRel( energy.distributions()[1].energies()[17] ) );
  CHECK_THAT( 20.736     , WithinRel( energy.distributions()[1].energies()[18] ) );
  CHECK_THAT( 1.84823    , WithinRel( energy.distributions()[1].values()[0] ) );
  CHECK_THAT( 1.26507    , WithinRel( energy.distributions()[1].values()[1] ) );
  CHECK_THAT(  .00885527 , WithinRel( energy.distributions()[1].values()[17] ) );
  CHECK_THAT(  .00876641 , WithinRel( energy.distributions()[1].values()[18] ) );
  CHECK_THAT( .100000000 , WithinRel( energy.distributions()[8].energies()[0] ) );
  CHECK_THAT( .128640000 , WithinRel( energy.distributions()[8].energies()[1] ) );
  CHECK_THAT(  9981470.  , WithinRel( energy.distributions()[8].energies()[83] ) );
  CHECK_THAT(  1e+7      , WithinRel( energy.distributions()[8].energies()[84] ) );
  CHECK_THAT( .608334000 , WithinRel( energy.distributions()[8].values()[0] ) );
  CHECK_THAT( .472898000 , WithinRel( energy.distributions()[8].values()[1] ) );
  CHECK_THAT( 9.28343e-12, WithinRel( energy.distributions()[8].values()[83] ) );
  CHECK_THAT( 5.8374e-12 , WithinRel( energy.distributions()[8].values()[84] ) );
  CHECK_THAT(  .100000000, WithinRel( energy.distributions()[9].energies()[0] ) );
  CHECK_THAT(  .148551000, WithinRel( energy.distributions()[9].energies()[1] ) );
  CHECK_THAT( 9.99082E+10, WithinRel( energy.distributions()[9].energies()[109] ) );
  CHECK_THAT(       1e+11, WithinRel( energy.distributions()[9].energies()[110] ) );
  CHECK_THAT(  .365591000, WithinRel( energy.distributions()[9].values()[0] ) );
  CHECK_THAT(  .246105000, WithinRel( energy.distributions()[9].values()[1] ) );
  CHECK_THAT( 9.06486E-16, WithinRel( energy.distributions()[9].values()[109] ) );
  CHECK_THAT( 5.16344E-16, WithinRel( energy.distributions()[9].values()[110] ) );
  CHECK( 9 == energy.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == energy.interpolants()[0] );
  auto electron = bremsstrahlung.products()[1];
  CHECK( id::ParticleID( "e-" ) == electron.identifier() );
  CHECK( true == electron.isLinearised() );
  CHECK( true == electron.hasAverageEnergy() );
  CHECK( false == electron.hasDistributionData() );
  CHECK( true == std::holds_alternative< int >( electron.multiplicity() ) );
  multiplicity = std::get< int >( electron.multiplicity() );
  CHECK( 1 == multiplicity );
  CHECK( std::nullopt != electron.averageEnergy() );
  auto average = electron.averageEnergy().value();
  CHECK( true == average.isLinearised() );
  CHECK( 82 == average.numberPoints() );
  CHECK( 1 == average.numberRegions() );
  CHECK( 82 == average.energies().size() );
  CHECK( 82 == average.values().size() );
  CHECK( 1 == average.boundaries().size() );
  CHECK( 1 == average.interpolants().size() );
  CHECK( 81 == average.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == average.interpolants()[0] );
  CHECK_THAT( 10.        , WithinRel( average.energies()[0] ) );
  CHECK_THAT( 14.4       , WithinRel( average.energies()[1] ) );
  CHECK_THAT( 7.86876E+10, WithinRel( average.energies()[80] ) );
  CHECK_THAT(       1e+11, WithinRel( average.energies()[81] ) );
  CHECK_THAT(  10.         - 2.14426   , WithinRel( average.values()[0] ) );
  CHECK_THAT(  14.4        - 2.87181   , WithinRel( average.values()[1] ) );
  CHECK_THAT(  7.86876E+10 - 2.11850E+9, WithinRel( average.values()[80] ) );
  CHECK_THAT(  1e+11       - 2.66810E+9, WithinRel( average.values()[81] ) );
  CHECK( std::nullopt == electron.distributionData() );
}

void verifyElectronExcitationReaction( const Reaction& subionisation ) {

  CHECK( id::ReactionID( "528" ) == subionisation.identifier() );
  CHECK( ReactionType::Primary == subionisation.type() );
  CHECK( true == subionisation.hasProducts() );
  CHECK( true == subionisation.isLinearised() );

  CHECK( std::nullopt == subionisation.massDifferenceQValue() );
  CHECK( std::nullopt != subionisation.reactionQValue() );
  CHECK_THAT( 0., WithinRel( subionisation.reactionQValue().value() ) );

  CHECK( true == subionisation.crossSection().isLinearised() );
  CHECK( 170 == subionisation.crossSection().numberPoints() );
  CHECK( 1 == subionisation.crossSection().numberRegions() );
  CHECK( 170 == subionisation.crossSection().energies().size() );
  CHECK( 170 == subionisation.crossSection().values().size() );
  CHECK( 1 == subionisation.crossSection().boundaries().size() );
  CHECK( 1 == subionisation.crossSection().interpolants().size() );
  CHECK( 169 == subionisation.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == subionisation.crossSection().interpolants()[0] );
  CHECK_THAT( 13.6, WithinRel( subionisation.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( subionisation.crossSection().energies()[169] ) );
  CHECK_THAT( 0. , WithinRel( subionisation.crossSection().values()[0] ) );
  CHECK_THAT( 81441.6, WithinRel( subionisation.crossSection().values()[169] ) );

  CHECK( 1 == subionisation.products().size() );
  auto electron = subionisation.products()[0];
  CHECK( id::ParticleID( "e-" ) == electron.identifier() );
  CHECK( true == electron.isLinearised() );
  CHECK( true == electron.hasAverageEnergy() );
  CHECK( false == electron.hasDistributionData() );
  CHECK( true == std::holds_alternative< int >( electron.multiplicity() ) );
  auto multiplicity = std::get< int >( electron.multiplicity() );
  CHECK( 1 == multiplicity );
  CHECK( std::nullopt != electron.averageEnergy() );
  auto average = electron.averageEnergy().value();
  CHECK( true == average.isLinearised() );
  CHECK( 170 == average.numberPoints() );
  CHECK( 1 == average.numberRegions() );
  CHECK( 170 == average.energies().size() );
  CHECK( 170 == average.values().size() );
  CHECK( 1 == average.boundaries().size() );
  CHECK( 1 == average.interpolants().size() );
  CHECK( 169 == average.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == average.interpolants()[0] );
  CHECK_THAT( 13.6       , WithinRel( average.energies()[0] ) );
  CHECK_THAT( 13.7740142 , WithinRel( average.energies()[1] ) );
  CHECK_THAT(       9e+10, WithinRel( average.energies()[168] ) );
  CHECK_THAT(       1e+11, WithinRel( average.energies()[169] ) );
  CHECK_THAT(  13.6        - 13.6      , WithinRel( average.values()[0] ) );
  CHECK_THAT(  13.7740142  - 13.6069279, WithinRel( average.values()[1] ) );
  CHECK_THAT(  9e+10       - 21.0777000, WithinRel( average.values()[168] ) );
  CHECK_THAT(  1e+11       - 21.0777000, WithinRel( average.values()[169] ) );
  CHECK( std::nullopt == electron.distributionData() );
}

void verifyElectronSubshellIonisationReaction( const Reaction& subionisation ) {

  CHECK( id::ReactionID( "534" ) == subionisation.identifier() );
  CHECK( ReactionType::Primary == subionisation.type() );
  CHECK( true == subionisation.hasProducts() );
  CHECK( true == subionisation.isLinearised() );

  CHECK( std::nullopt == subionisation.massDifferenceQValue() );
  CHECK( std::nullopt != subionisation.reactionQValue() );
  CHECK_THAT( -13.6, WithinRel( subionisation.reactionQValue().value() ) );

  CHECK( true == subionisation.crossSection().isLinearised() );
  CHECK( 35 == subionisation.crossSection().numberPoints() );
  CHECK( 1 == subionisation.crossSection().numberRegions() );
  CHECK( 35 == subionisation.crossSection().energies().size() );
  CHECK( 35 == subionisation.crossSection().values().size() );
  CHECK( 1 == subionisation.crossSection().boundaries().size() );
  CHECK( 1 == subionisation.crossSection().interpolants().size() );
  CHECK( 34 == subionisation.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == subionisation.crossSection().interpolants()[0] );
  CHECK_THAT( 13.6, WithinRel( subionisation.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( subionisation.crossSection().energies()[34] ) );
  CHECK_THAT( 0. , WithinRel( subionisation.crossSection().values()[0] ) );
  CHECK_THAT( 82892.4, WithinRel( subionisation.crossSection().values()[34] ) );

  CHECK( 1 == subionisation.products().size() );
  auto electron = subionisation.products()[0];
  CHECK( id::ParticleID( "e-" ) == electron.identifier() );
  CHECK( true == electron.isLinearised() );
  CHECK( false == electron.hasAverageEnergy() );
  CHECK( true == electron.hasDistributionData() );
  CHECK( true == std::holds_alternative< int >( electron.multiplicity() ) );
  auto multiplicity = std::get< int >( electron.multiplicity() );
  CHECK( 1 == multiplicity );
  CHECK( std::nullopt == electron.averageEnergy() );
  CHECK( std::nullopt != electron.distributionData() );
  CHECK( true == std::holds_alternative< UncorrelatedDistributionData >( electron.distributionData().value() ) );
  auto data = std::get< UncorrelatedDistributionData >( electron.distributionData().value() );
  CHECK( DistributionDataType::Uncorrelated == data.type() );
  CHECK( true == std::holds_alternative< IsotropicAngularDistributions >( data.angle() ) );
  CHECK( true == std::holds_alternative< TabulatedEnergyDistributions >( data.energy() ) );
  auto energy = std::get< TabulatedEnergyDistributions >( data.energy() );
  CHECK( 8 == energy.numberPoints() );
  CHECK( 1 == energy.numberRegions() );
  CHECK( 8 == energy.grid().size() );
  CHECK( 8 == energy.distributions().size() );
  CHECK( 1 == energy.boundaries().size() );
  CHECK( 1 == energy.interpolants().size() );
  CHECK_THAT(   13.6  , WithinRel( energy.grid()[0] ) );
  CHECK_THAT(   14.28 , WithinRel( energy.grid()[1] ) );
  CHECK_THAT( 50118700, WithinRel( energy.grid()[6] ) );
  CHECK_THAT(   1e+11 , WithinRel( energy.grid()[7] ) );
  CHECK(  2 == energy.distributions()[0].energies().size() );
  CHECK(  2 == energy.distributions()[0].values().size() );
  CHECK(  2 == energy.distributions()[1].energies().size() );
  CHECK(  2 == energy.distributions()[1].values().size() );
  CHECK( 100 == energy.distributions()[6].energies().size() );
  CHECK( 100 == energy.distributions()[6].values().size() );
  CHECK( 147 == energy.distributions()[7].energies().size() );
  CHECK( 147 == energy.distributions()[7].values().size() );
  CHECK_THAT(  0.00279866, WithinRel( energy.distributions()[0].energies()[0] ) );
  CHECK_THAT(  0.0279866  , WithinRel( energy.distributions()[0].energies()[1] ) );
  CHECK_THAT( 39.7015    , WithinRel( energy.distributions()[0].values()[0] ) );
  CHECK_THAT( 39.7015    , WithinRel( energy.distributions()[0].values()[1] ) );
  CHECK_THAT(  .00279866 , WithinRel( energy.distributions()[1].energies()[0] ) );
  CHECK_THAT(  .279866   , WithinRel( energy.distributions()[1].energies()[1] ) );
  CHECK_THAT( 3.67711    , WithinRel( energy.distributions()[1].values()[0] ) );
  CHECK_THAT( 3.54135    , WithinRel( energy.distributions()[1].values()[1] ) );
  CHECK_THAT( .100000000 , WithinRel( energy.distributions()[6].energies()[0] ) );
  CHECK_THAT( .630957000 , WithinRel( energy.distributions()[6].energies()[1] ) );
  CHECK_THAT(  19952600. , WithinRel( energy.distributions()[6].energies()[98] ) );
  CHECK_THAT(  25059400  , WithinRel( energy.distributions()[6].energies()[99] ) );
  CHECK_THAT( .161903    , WithinRel( energy.distributions()[6].values()[0] ) );
  CHECK_THAT(  .143109000, WithinRel( energy.distributions()[6].values()[1] ) );
  CHECK_THAT( 1.22367E-14, WithinRel( energy.distributions()[6].values()[98] ) );
  CHECK_THAT( 1.09273E-14, WithinRel( energy.distributions()[6].values()[99] ) );
  CHECK_THAT(  .100000000, WithinRel( energy.distributions()[7].energies()[0] ) );
  CHECK_THAT(  .630957000, WithinRel( energy.distributions()[7].energies()[1] ) );
  CHECK_THAT( 3.98107E+10, WithinRel( energy.distributions()[7].energies()[145] ) );
  CHECK_THAT(       5e+10, WithinRel( energy.distributions()[7].energies()[146] ) );
  CHECK_THAT(  .161897000, WithinRel( energy.distributions()[7].values()[0] ) );
  CHECK_THAT(  .143104000, WithinRel( energy.distributions()[7].values()[1] ) );
  CHECK_THAT( 3.10545E-21, WithinRel( energy.distributions()[7].values()[145] ) );
  CHECK_THAT(  2.7755E-21, WithinRel( energy.distributions()[7].values()[146] ) );
  CHECK( 7 == energy.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == energy.interpolants()[0] );
}

void verifyPhotonTotalReaction( const Reaction& total ) {

  CHECK( id::ReactionID( "501" ) == total.identifier() );
  CHECK( ReactionType::Summation == total.type() );
  CHECK( false == total.hasProducts() );
  CHECK( true == total.isLinearised() );

  CHECK( std::nullopt != total.partialReactionIdentifiers() );
  auto partials = total.partialReactionIdentifiers().value();
  CHECK( 5 == partials.size() );
  CHECK( id::ReactionID( "502" ) == partials[0] );
  CHECK( id::ReactionID( "504" ) == partials[1] );
  CHECK( id::ReactionID( "515" ) == partials[2] );
  CHECK( id::ReactionID( "517" ) == partials[3] );
  CHECK( id::ReactionID( "534" ) == partials[4] );

  CHECK( std::nullopt == total.massDifferenceQValue() );
  CHECK( std::nullopt == total.reactionQValue() );

  CHECK( true == total.crossSection().isLinearised() );
  CHECK( 2021 == total.crossSection().numberPoints() );
  CHECK( 2 == total.crossSection().numberRegions() );
  CHECK( 2021 == total.crossSection().energies().size() );
  CHECK( 2021 == total.crossSection().values().size() );
  CHECK( 2 == total.crossSection().boundaries().size() );
  CHECK( 2 == total.crossSection().interpolants().size() );
  CHECK(  137 == total.crossSection().boundaries()[0] );
  CHECK( 2020 == total.crossSection().boundaries()[1] );
  CHECK( InterpolationType::LinearLinear == total.crossSection().interpolants()[0] );
  CHECK( InterpolationType::LinearLinear == total.crossSection().interpolants()[1] );
  CHECK_THAT( 1.   , WithinRel( total.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( total.crossSection().energies()[2020] ) );
  CHECK_THAT( 4.62084E-6, WithinRel( total.crossSection().values()[0] ) );
  CHECK_THAT( .020718042, WithinRel( total.crossSection().values()[2020] ) );

  CHECK( 0 == total.products().size() );
}

void verifyPhotonCoherentReaction( const Reaction& coherent ) {

  CHECK( id::ReactionID( "502" ) == coherent.identifier() );
  CHECK( ReactionType::Primary == coherent.type() );
  CHECK( true == coherent.hasProducts() );
  CHECK( true == coherent.isLinearised() );

  CHECK( std::nullopt == coherent.massDifferenceQValue() );
  CHECK( std::nullopt != coherent.reactionQValue() );
  CHECK_THAT( 0., WithinRel( coherent.reactionQValue().value() ) );

  CHECK( true == coherent.crossSection().isLinearised() );
  CHECK( 361 == coherent.crossSection().numberPoints() );
  CHECK( 1 == coherent.crossSection().numberRegions() );
  CHECK( 361 == coherent.crossSection().energies().size() );
  CHECK( 361 == coherent.crossSection().values().size() );
  CHECK( 1 == coherent.crossSection().boundaries().size() );
  CHECK( 1 == coherent.crossSection().interpolants().size() );
  CHECK( 360 == coherent.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == coherent.crossSection().interpolants()[0] );
  CHECK_THAT( 1.   , WithinRel( coherent.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( coherent.crossSection().energies()[360] ) );
  CHECK_THAT( 4.52522E-6, WithinRel( coherent.crossSection().values()[0] ) );
  CHECK_THAT( 4.6282E-16, WithinRel( coherent.crossSection().values()[360] ) );

  CHECK( 1 == coherent.products().size() );

  auto gamma = coherent.products()[0];
  CHECK( id::ParticleID( "g" ) == gamma.identifier() );
  CHECK( true == gamma.isLinearised() );
  CHECK( false == gamma.hasAverageEnergy() );
  CHECK( true == gamma.hasDistributionData() );

  CHECK( true == std::holds_alternative< int >( gamma.multiplicity() ) );
  auto multiplicity = std::get< int >( gamma.multiplicity() );
  CHECK( 1 == multiplicity );

  CHECK( std::nullopt == gamma.averageEnergy() );

  CHECK( std::nullopt != gamma.distributionData() );
  CHECK( true == std::holds_alternative< CoherentDistributionData >( gamma.distributionData().value() ) );
  auto data = std::get< CoherentDistributionData >( gamma.distributionData().value() );

  CHECK( DistributionDataType::Coherent == data.type() );
  CHECK( ReferenceFrame::CentreOfMass == data.frame() );

  CHECK_THAT( 0.  , WithinRel( data.scatteringFunction().lowerInverseLengthLimit() ) );
  CHECK_THAT( 1e+9, WithinRel( data.scatteringFunction().upperInverseLengthLimit() ) );
  CHECK( 1253 == data.scatteringFunction().inverseLengths().size() );
  CHECK( 1253 == data.scatteringFunction().values().size() );
  CHECK( 1 == data.scatteringFunction().boundaries().size() );
  CHECK( 1 == data.scatteringFunction().interpolants().size() );
  CHECK_THAT( 0.       , WithinRel( data.scatteringFunction().inverseLengths()[0] ) );
  CHECK_THAT( 0.001    , WithinRel( data.scatteringFunction().inverseLengths()[1] ) );
  CHECK_THAT( 512000000, WithinRel( data.scatteringFunction().inverseLengths()[1251] ) );
  CHECK_THAT( 1e+9     , WithinRel( data.scatteringFunction().inverseLengths()[1252] ) );
  CHECK_THAT( 1.        , WithinRel( data.scatteringFunction().values()[0] ) );
  CHECK_THAT( 1.        , WithinRel( data.scatteringFunction().values()[1] ) );
  CHECK_THAT( 1.1908E-37, WithinRel( data.scatteringFunction().values()[1251] ) );
  CHECK_THAT( 8.1829e-39, WithinRel( data.scatteringFunction().values()[1252] ) );
  CHECK( 1252 == data.scatteringFunction().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == data.scatteringFunction().interpolants()[0] );
  CHECK( true == data.scatteringFunction().isLinearised() );

  CHECK( std::nullopt != data.realAnomolousFormFactor() );
  auto factor = data.realAnomolousFormFactor().value();
  CHECK_THAT( 1.  , WithinRel( factor.lowerEnergyLimit() ) );
  CHECK_THAT( 1e+7, WithinRel( factor.upperEnergyLimit() ) );
  CHECK( 297 == factor.energies().size() );
  CHECK( 297 == factor.values().size() );
  CHECK( 1 == factor.boundaries().size() );
  CHECK( 1 == factor.interpolants().size() );
  CHECK_THAT( 1.        , WithinRel( factor.energies()[0] ) );
  CHECK_THAT( 2.        , WithinRel( factor.energies()[1] ) );
  CHECK_THAT( 9549925.86, WithinRel( factor.energies()[295] ) );
  CHECK_THAT( 1e+7      , WithinRel( factor.energies()[296] ) );
  CHECK_THAT( 0.        , WithinRel( factor.values()[0] ) );
  CHECK_THAT( 0.        , WithinRel( factor.values()[1] ) );
  CHECK_THAT( 8.9767E-15, WithinRel( factor.values()[295] ) );
  CHECK_THAT( 0.        , WithinRel( factor.values()[296] ) );
  CHECK( 296 == factor.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == factor.interpolants()[0] );
  CHECK( true == factor.isLinearised() );

  CHECK( std::nullopt != data.imaginaryAnomolousFormFactor() );
  factor = data.imaginaryAnomolousFormFactor().value();
  CHECK_THAT( 1.  , WithinRel( factor.lowerEnergyLimit() ) );
  CHECK_THAT( 1e+7, WithinRel( factor.upperEnergyLimit() ) );
  CHECK( 297 == factor.energies().size() );
  CHECK( 297 == factor.values().size() );
  CHECK( 1 == factor.boundaries().size() );
  CHECK( 1 == factor.interpolants().size() );
  CHECK_THAT( 1.        , WithinRel( factor.energies()[0] ) );
  CHECK_THAT( 2.        , WithinRel( factor.energies()[1] ) );
  CHECK_THAT( 9549925.86, WithinRel( factor.energies()[295] ) );
  CHECK_THAT( 1e+7      , WithinRel( factor.energies()[296] ) );
  CHECK_THAT( -1.00260813, WithinRel( factor.values()[0] ) );
  CHECK_THAT( -1.01054501, WithinRel( factor.values()[1] ) );
  CHECK_THAT( 2.8024E-11, WithinRel( factor.values()[295] ) );
  CHECK_THAT( 0.        , WithinRel( factor.values()[296] ) );
  CHECK( 296 == factor.boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == factor.interpolants()[0] );
  CHECK( true == factor.isLinearised() );
}

void verifyPhotonIncoherentReaction( const Reaction& incoherent ) {

  CHECK( id::ReactionID( "504" ) == incoherent.identifier() );
  CHECK( ReactionType::Primary == incoherent.type() );
  CHECK( true == incoherent.hasProducts() );
  CHECK( true == incoherent.isLinearised() );

  CHECK( std::nullopt == incoherent.massDifferenceQValue() );
  CHECK( std::nullopt != incoherent.reactionQValue() );
  CHECK_THAT( 0., WithinRel( incoherent.reactionQValue().value() ) );

  CHECK( true == incoherent.crossSection().isLinearised() );
  CHECK( 396 == incoherent.crossSection().numberPoints() );
  CHECK( 1 == incoherent.crossSection().numberRegions() );
  CHECK( 396 == incoherent.crossSection().energies().size() );
  CHECK( 396 == incoherent.crossSection().values().size() );
  CHECK( 1 == incoherent.crossSection().boundaries().size() );
  CHECK( 1 == incoherent.crossSection().interpolants().size() );
  CHECK( 395 == incoherent.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == incoherent.crossSection().interpolants()[0] );
  CHECK_THAT( 1.   , WithinRel( incoherent.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11, WithinRel( incoherent.crossSection().energies()[395] ) );
  CHECK_THAT( 9.56230E-8, WithinRel( incoherent.crossSection().values()[0] ) );
  CHECK_THAT( 1.70420E-5, WithinRel( incoherent.crossSection().values()[395] ) );

  CHECK( 1 == incoherent.products().size() );

  auto gamma = incoherent.products()[0];
  CHECK( id::ParticleID( "g" ) == gamma.identifier() );
  CHECK( true == gamma.isLinearised() );
  CHECK( false == gamma.hasAverageEnergy() );
  CHECK( true == gamma.hasDistributionData() );

  CHECK( true == std::holds_alternative< int >( gamma.multiplicity() ) );
  auto multiplicity = std::get< int >( gamma.multiplicity() );
  CHECK( 1 == multiplicity );

  CHECK( std::nullopt == gamma.averageEnergy() );

  CHECK( std::nullopt != gamma.distributionData() );
  CHECK( true == std::holds_alternative< IncoherentDistributionData >( gamma.distributionData().value() ) );
  auto data = std::get< IncoherentDistributionData >( gamma.distributionData().value() );

  CHECK( DistributionDataType::Incoherent == data.type() );
  CHECK( ReferenceFrame::CentreOfMass == data.frame() );

  CHECK_THAT( 0.  , WithinRel( data.scatteringFunction().lowerInverseLengthLimit() ) );
  CHECK_THAT( 1e+9, WithinRel( data.scatteringFunction().upperInverseLengthLimit() ) );
  CHECK( 398 == data.scatteringFunction().inverseLengths().size() );
  CHECK( 398 == data.scatteringFunction().values().size() );
  CHECK( 1 == data.scatteringFunction().boundaries().size() );
  CHECK( 1 == data.scatteringFunction().interpolants().size() );
  CHECK_THAT( 0.       , WithinRel( data.scatteringFunction().inverseLengths()[0] ) );
  CHECK_THAT( 1e-7     , WithinRel( data.scatteringFunction().inverseLengths()[1] ) );
  CHECK_THAT( 512000000, WithinRel( data.scatteringFunction().inverseLengths()[396] ) );
  CHECK_THAT( 1e+9     , WithinRel( data.scatteringFunction().inverseLengths()[397] ) );
  CHECK_THAT( 0.        , WithinRel( data.scatteringFunction().values()[0] ) );
  CHECK_THAT( 4.4097E-13, WithinRel( data.scatteringFunction().values()[1] ) );
  CHECK_THAT( 1.        , WithinRel( data.scatteringFunction().values()[396] ) );
  CHECK_THAT( 1.        , WithinRel( data.scatteringFunction().values()[397] ) );
  CHECK( 397 == data.scatteringFunction().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == data.scatteringFunction().interpolants()[0] );
  CHECK( true == data.scatteringFunction().isLinearised() );
}

void verifyPhotonElectronFieldPairProductionReaction( const Reaction& epairproduction ) {

  CHECK( id::ReactionID( "515" ) == epairproduction.identifier() );
  CHECK( ReactionType::Primary == epairproduction.type() );
  CHECK( false == epairproduction.hasProducts() );
  CHECK( true == epairproduction.isLinearised() );

  CHECK( std::nullopt == epairproduction.massDifferenceQValue() );
  CHECK( std::nullopt != epairproduction.reactionQValue() );
  CHECK_THAT( 0., WithinRel( epairproduction.reactionQValue().value() ) );

  CHECK( true == epairproduction.crossSection().isLinearised() );
  CHECK( 217 == epairproduction.crossSection().numberPoints() );
  CHECK( 1 == epairproduction.crossSection().numberRegions() );
  CHECK( 217 == epairproduction.crossSection().energies().size() );
  CHECK( 217 == epairproduction.crossSection().values().size() );
  CHECK( 1 == epairproduction.crossSection().boundaries().size() );
  CHECK( 1 == epairproduction.crossSection().interpolants().size() );
  CHECK( 216 == epairproduction.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == epairproduction.crossSection().interpolants()[0] );
  CHECK_THAT( 2044000., WithinRel( epairproduction.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11   , WithinRel( epairproduction.crossSection().energies()[216] ) );
  CHECK_THAT( 0.      , WithinRel( epairproduction.crossSection().values()[0] ) );
  CHECK_THAT( .0111   , WithinRel( epairproduction.crossSection().values()[216] ) );

  CHECK( 0 == epairproduction.products().size() );
}

void verifyPhotonNuclearFieldPairProductionReaction( const Reaction& npairproduction ) {

  CHECK( id::ReactionID( "517" ) == npairproduction.identifier() );
  CHECK( ReactionType::Primary == npairproduction.type() );
  CHECK( false == npairproduction.hasProducts() );
  CHECK( true == npairproduction.isLinearised() );

  CHECK( std::nullopt == npairproduction.massDifferenceQValue() );
  CHECK( std::nullopt != npairproduction.reactionQValue() );
  CHECK_THAT( 0., WithinRel( npairproduction.reactionQValue().value() ) );

  CHECK( true == npairproduction.crossSection().isLinearised() );
  CHECK( 308 == npairproduction.crossSection().numberPoints() );
  CHECK( 1 == npairproduction.crossSection().numberRegions() );
  CHECK( 308 == npairproduction.crossSection().energies().size() );
  CHECK( 308 == npairproduction.crossSection().values().size() );
  CHECK( 1 == npairproduction.crossSection().boundaries().size() );
  CHECK( 1 == npairproduction.crossSection().interpolants().size() );
  CHECK( 307 == npairproduction.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == npairproduction.crossSection().interpolants()[0] );
  CHECK_THAT( 1022000., WithinRel( npairproduction.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11   , WithinRel( npairproduction.crossSection().energies()[307] ) );
  CHECK_THAT( 0.      , WithinRel( npairproduction.crossSection().values()[0] ) );
  CHECK_THAT( .009601 , WithinRel( npairproduction.crossSection().values()[307] ) );

  CHECK( 0 == npairproduction.products().size() );
}

void verifyPhotonTotalPairProductionReaction( const Reaction& tpairproduction ) {

  CHECK( id::ReactionID( "516" ) == tpairproduction.identifier() );
  CHECK( ReactionType::Summation == tpairproduction.type() );
  CHECK( false == tpairproduction.hasProducts() );
  CHECK( true == tpairproduction.isLinearised() );

  CHECK( std::nullopt != tpairproduction.partialReactionIdentifiers() );
  auto partials = tpairproduction.partialReactionIdentifiers().value();
  CHECK( 2 == partials.size() );
  CHECK( id::ReactionID( "515" ) == partials[0] );
  CHECK( id::ReactionID( "517" ) == partials[1] );

  CHECK( std::nullopt == tpairproduction.massDifferenceQValue() );
  CHECK( std::nullopt == tpairproduction.reactionQValue() );

  CHECK( true == tpairproduction.crossSection().isLinearised() );
  CHECK( 466 == tpairproduction.crossSection().numberPoints() );
  CHECK( 1 == tpairproduction.crossSection().numberRegions() );
  CHECK( 466 == tpairproduction.crossSection().energies().size() );
  CHECK( 466 == tpairproduction.crossSection().values().size() );
  CHECK( 1 == tpairproduction.crossSection().boundaries().size() );
  CHECK( 1 == tpairproduction.crossSection().interpolants().size() );
  CHECK( 465 == tpairproduction.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == tpairproduction.crossSection().interpolants()[0] );
  CHECK_THAT( 1022000., WithinRel( tpairproduction.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11   , WithinRel( tpairproduction.crossSection().energies()[465] ) );
  CHECK_THAT( 0.      , WithinRel( tpairproduction.crossSection().values()[0] ) );
  CHECK_THAT( .020701 , WithinRel( tpairproduction.crossSection().values()[465] ) );

  CHECK( 0 == tpairproduction.products().size() );
}

void verifyPhotonIonisationReaction( const Reaction& ionisation ) {

  CHECK( id::ReactionID( "534" ) == ionisation.identifier() );
  CHECK( ReactionType::Primary == ionisation.type() );
  CHECK( false == ionisation.hasProducts() );
  CHECK( true == ionisation.isLinearised() );

  CHECK( std::nullopt == ionisation.massDifferenceQValue() );
  CHECK( std::nullopt != ionisation.reactionQValue() );
  CHECK_THAT( -13.6, WithinRel( ionisation.reactionQValue().value() ) );

  CHECK( true == ionisation.crossSection().isLinearised() );
  CHECK( 904 == ionisation.crossSection().numberPoints() );
  CHECK( 1 == ionisation.crossSection().numberRegions() );
  CHECK( 904 == ionisation.crossSection().energies().size() );
  CHECK( 904 == ionisation.crossSection().values().size() );
  CHECK( 1 == ionisation.crossSection().boundaries().size() );
  CHECK( 1 == ionisation.crossSection().interpolants().size() );
  CHECK( 903 == ionisation.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == ionisation.crossSection().interpolants()[0] );
  CHECK_THAT( 13.6    , WithinRel( ionisation.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11   , WithinRel( ionisation.crossSection().energies()[903] ) );
  CHECK_THAT( 6318358.25, WithinRel( ionisation.crossSection().values()[0] ) );
  CHECK_THAT( 7.7360E-15, WithinRel( ionisation.crossSection().values()[903] ) );

  CHECK( 0 == ionisation.products().size() );
}

void verifyPhotonTotalIonisationReaction( const Reaction& tionisation ) {

  CHECK( id::ReactionID( "522" ) == tionisation.identifier() );
  CHECK( ReactionType::Summation == tionisation.type() );
  CHECK( false == tionisation.hasProducts() );
  CHECK( true == tionisation.isLinearised() );

  CHECK( std::nullopt != tionisation.partialReactionIdentifiers() );
  auto partials = tionisation.partialReactionIdentifiers().value();
  CHECK( 1 == partials.size() );
  CHECK( id::ReactionID( "534" ) == partials[0] );

  CHECK( std::nullopt == tionisation.massDifferenceQValue() );
  CHECK( std::nullopt == tionisation.reactionQValue() );

  CHECK( true == tionisation.crossSection().isLinearised() );
  CHECK( 904 == tionisation.crossSection().numberPoints() );
  CHECK( 1 == tionisation.crossSection().numberRegions() );
  CHECK( 904 == tionisation.crossSection().energies().size() );
  CHECK( 904 == tionisation.crossSection().values().size() );
  CHECK( 1 == tionisation.crossSection().boundaries().size() );
  CHECK( 1 == tionisation.crossSection().interpolants().size() );
  CHECK( 903 == tionisation.crossSection().boundaries()[0] );
  CHECK( InterpolationType::LinearLinear == tionisation.crossSection().interpolants()[0] );
  CHECK_THAT( 13.6    , WithinRel( tionisation.crossSection().energies()[0] ) );
  CHECK_THAT( 1e+11   , WithinRel( tionisation.crossSection().energies()[903] ) );
  CHECK_THAT( 6318358.25, WithinRel( tionisation.crossSection().values()[0] ) );
  CHECK_THAT( 7.7360E-15, WithinRel( tionisation.crossSection().values()[903] ) );

  CHECK( 0 == tionisation.products().size() );
}

void verifyElectronElasticDeficitReaction( const Reaction& deficit ) {

  CHECK( id::ReactionID( "-526" ) == deficit.identifier() );
  CHECK( ReactionType::Primary == deficit.type() );
  CHECK( false == deficit.hasProducts() );
  CHECK( true == deficit.isLinearised() );

  CHECK( std::nullopt == deficit.partialReactionIdentifiers() );

  CHECK( std::nullopt == deficit.massDifferenceQValue() );
  CHECK( std::nullopt != deficit.reactionQValue() );

  CHECK( true == deficit.crossSection().isLinearised() );

  CHECK( 0 == deficit.products().size() );
}
