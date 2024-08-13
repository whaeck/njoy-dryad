// include Catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
using Catch::Matchers::WithinRel;

// what we are testing
#include "dryad/format/endf/createReaction.hpp"

// other includes
#include "ENDFtk/tree/fromFile.hpp"

// convenience typedefs
using namespace njoy::dryad;

// include common test verification functions
#include "test_verification_functions.hpp"

SCENARIO( "createReaction" ) {

  GIVEN( "ENDF materials - incident neutrons" ) {

    auto tape = njoy::ENDFtk::tree::fromFile( "n-001_H_001.endf" );
    auto material = tape.materials().front();

    WHEN( "a single ENDF material and MT number is given" ) {

      THEN( "a Reaction can be created" ) {

        id::ParticleID projectile( "n" );
        id::ParticleID target( "H1" );

        Reaction total = format::endf::createReaction( projectile, target, material, 1 );
        verifyNeutronTotalReaction( total );

        Reaction elastic = format::endf::createReaction( projectile, target, material, 2 );
        verifyNeutronElasticReaction( elastic );

        Reaction capture = format::endf::createReaction( projectile, target, material, 102 );
        verifyNeutronCaptureReaction( capture );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "ENDF materials - electro-atomic" ) {

    auto tape = njoy::ENDFtk::tree::fromFile( "e-001_H_000.endf" );
    auto material = tape.materials().front();

    WHEN( "a single ENDF material and MT number is given" ) {

      THEN( "a Reaction can be created" ) {

        id::ParticleID projectile( "e-" );
        id::ParticleID target( "H" );

        Reaction total = format::endf::createReaction( projectile, target, material, 501 );
        verifyElectronTotalReaction( total );

        Reaction ionisation = format::endf::createReaction( projectile, target, material, 522 );
        verifyElectronTotalIonisationReaction( ionisation );

        Reaction elastic = format::endf::createReaction( projectile, target, material, 525 );
        verifyElectronElasticReaction( elastic );

        Reaction telastic = format::endf::createReaction( projectile, target, material, 526 );
        verifyElectronTotalElasticReaction( telastic );

        Reaction bremsstrahlung = format::endf::createReaction( projectile, target, material, 527 );
        verifyElectronBremsstrahlungReaction( bremsstrahlung );

        Reaction excitation = format::endf::createReaction( projectile, target, material, 528 );
        verifyElectronExcitationReaction( excitation );

        Reaction subionisation = format::endf::createReaction( projectile, target, material, 534 );
        verifyElectronSubshellIonisationReaction( subionisation );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "ENDF materials - photo-atomic" ) {

    auto tape = njoy::ENDFtk::tree::fromFile( "photoat-001_H_000.endf" );
    auto material = tape.materials().front();

    WHEN( "a single ENDF material and MT number is given" ) {

      THEN( "a Reaction can be created" ) {

        id::ParticleID projectile( "g" );
        id::ParticleID target( "H" );

        Reaction total = format::endf::createReaction( projectile, target, material, 501 );
        verifyPhotonTotalReaction( total );

        Reaction coherent = format::endf::createReaction( projectile, target, material, 502 );
        verifyPhotonCoherentReaction( coherent );

        Reaction incoherent = format::endf::createReaction( projectile, target, material, 504 );
        verifyPhotonIncoherentReaction( incoherent );

        Reaction epairproduction = format::endf::createReaction( projectile, target, material, 515 );
        verifyPhotonElectronFieldPairProductionReaction( epairproduction );

        Reaction tpairproduction = format::endf::createReaction( projectile, target, material, 516 );
        verifyPhotonTotalPairProductionReaction( tpairproduction );

        Reaction npairproduction = format::endf::createReaction( projectile, target, material, 517 );
        verifyPhotonNuclearFieldPairProductionReaction( npairproduction );

        Reaction tionisation = format::endf::createReaction( projectile, target, material, 522 );
        verifyPhotonTotalIonisationReaction( tionisation );

        Reaction ionisation = format::endf::createReaction( projectile, target, material, 534 );
        verifyPhotonIonisationReaction( ionisation );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
