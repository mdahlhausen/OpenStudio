/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) Alliance for Sustainable Energy, LLC.
*  See also https://openstudio.net/license
***********************************************************************************************************************/

#include <gtest/gtest.h>

#include "ModelFixture.hpp"
#include "../Model.hpp"
#include "../Node.hpp"
#include "../Node_Impl.hpp"
#include "../AirLoopHVAC.hpp"
#include "../PlantLoop.hpp"
#include "../PlantLoop_Impl.hpp"
#include "../Splitter.hpp"
#include "../Splitter_Impl.hpp"
#include "../AirLoopHVACZoneSplitter.hpp"

#include "../CoilCoolingCooledBeam.hpp"
#include "../CoilCoolingCooledBeam_Impl.hpp"

using namespace openstudio;
using namespace openstudio::model;

TEST_F(ModelFixture, CoilCoolingCooledBeam_Test) {

  // test constructor
  Model model;
  CoilCoolingCooledBeam coilCoolingCooledBeam(model);

  // Field N1 Coil Surface Area per Coil Length
  coilCoolingCooledBeam.setCoilSurfaceAreaperCoilLength(5.0);
  boost::optional<double> testCoilSurfaceAreaperCoilLength = coilCoolingCooledBeam.coilSurfaceAreaperCoilLength();
  EXPECT_EQ(*testCoilSurfaceAreaperCoilLength, 5.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isCoilSurfaceAreaperCoilLengthDefaulted());
  coilCoolingCooledBeam.resetCoilSurfaceAreaperCoilLength();
  EXPECT_TRUE(coilCoolingCooledBeam.isCoilSurfaceAreaperCoilLengthDefaulted());
  // check Default
  testCoilSurfaceAreaperCoilLength = coilCoolingCooledBeam.coilSurfaceAreaperCoilLength();
  EXPECT_EQ(*testCoilSurfaceAreaperCoilLength, 5.422);

  // Field N2 Model Parameter a
  coilCoolingCooledBeam.setModelParametera(10.0);
  boost::optional<double> testModelParametera = coilCoolingCooledBeam.modelParametera();
  EXPECT_EQ(*testModelParametera, 10.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParameteraDefaulted());
  coilCoolingCooledBeam.resetModelParametera();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParameteraDefaulted());
  // check Default
  testModelParametera = coilCoolingCooledBeam.modelParametera();
  EXPECT_EQ(*testModelParametera, 15.3);

  // Field N3 Model Parameter n1
  coilCoolingCooledBeam.setModelParametern1(1.0);
  boost::optional<double> testModelParametern1 = coilCoolingCooledBeam.modelParametern1();
  EXPECT_EQ(*testModelParametern1, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParametern1Defaulted());
  coilCoolingCooledBeam.resetModelParametern1();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParametern1Defaulted());
  // check Default
  testModelParametern1 = coilCoolingCooledBeam.modelParametern1();
  EXPECT_EQ(*testModelParametern1, 0);

  // Field N4 Model Parameter n2
  coilCoolingCooledBeam.setModelParametern2(1.0);
  boost::optional<double> testModelParametern2 = coilCoolingCooledBeam.modelParametern2();
  EXPECT_EQ(*testModelParametern2, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParametern2Defaulted());
  coilCoolingCooledBeam.resetModelParametern2();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParametern2Defaulted());
  // check Default
  testModelParametern2 = coilCoolingCooledBeam.modelParametern2();
  EXPECT_EQ(*testModelParametern2, 0.84);

  // Field N5 Model Parameter n3
  coilCoolingCooledBeam.setModelParametern3(1.0);
  boost::optional<double> testModelParametern3 = coilCoolingCooledBeam.modelParametern3();
  EXPECT_EQ(*testModelParametern3, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParametern3Defaulted());
  coilCoolingCooledBeam.resetModelParametern3();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParametern3Defaulted());
  // check Default
  testModelParametern3 = coilCoolingCooledBeam.modelParametern3();
  EXPECT_EQ(*testModelParametern3, 0.12);

  // Field N6 Model Parameter a0
  coilCoolingCooledBeam.setModelParametera0(1.0);
  boost::optional<double> testModelParametera0 = coilCoolingCooledBeam.modelParametera0();
  EXPECT_EQ(*testModelParametera0, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParametera0Defaulted());
  coilCoolingCooledBeam.resetModelParametera0();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParametera0Defaulted());
  // check Default
  testModelParametera0 = coilCoolingCooledBeam.modelParametera0();
  EXPECT_EQ(*testModelParametera0, 0.171);

  // Field N7 Model Parameter K1
  coilCoolingCooledBeam.setModelParameterK1(1.0);
  boost::optional<double> testModelParameterK1 = coilCoolingCooledBeam.modelParameterK1();
  EXPECT_EQ(*testModelParameterK1, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParameterK1Defaulted());
  coilCoolingCooledBeam.resetModelParameterK1();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParameterK1Defaulted());
  // check Default
  testModelParameterK1 = coilCoolingCooledBeam.modelParameterK1();
  EXPECT_EQ(*testModelParameterK1, 0.0057);

  // Field N8 Model Parameter n
  coilCoolingCooledBeam.setModelParametern(1.0);
  boost::optional<double> testModelParametern = coilCoolingCooledBeam.modelParametern();
  EXPECT_EQ(*testModelParametern, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isModelParameternDefaulted());
  coilCoolingCooledBeam.resetModelParametern();
  EXPECT_TRUE(coilCoolingCooledBeam.isModelParameternDefaulted());
  // check Default
  testModelParametern = coilCoolingCooledBeam.modelParametern();
  EXPECT_EQ(*testModelParametern, 0.4);

  // Field N8 Leaving Pipe Inside Diameter
  coilCoolingCooledBeam.setLeavingPipeInsideDiameter(1.0);
  boost::optional<double> testLeavingPipeInsideDiameter = coilCoolingCooledBeam.leavingPipeInsideDiameter();
  EXPECT_EQ(*testLeavingPipeInsideDiameter, 1.0);
  EXPECT_FALSE(coilCoolingCooledBeam.isLeavingPipeInsideDiameterDefaulted());
  coilCoolingCooledBeam.resetLeavingPipeInsideDiameter();
  EXPECT_TRUE(coilCoolingCooledBeam.isLeavingPipeInsideDiameterDefaulted());
  // check Default
  testLeavingPipeInsideDiameter = coilCoolingCooledBeam.leavingPipeInsideDiameter();
  EXPECT_EQ(*testLeavingPipeInsideDiameter, 0.0145);

  // test inlet and outlet ports

  AirLoopHVAC airLoop(model);

  Node supplyOutletNode = airLoop.supplyOutletNode();
  EXPECT_FALSE(coilCoolingCooledBeam.addToNode(supplyOutletNode));
  EXPECT_EQ((unsigned)2, airLoop.supplyComponents().size());

  Node inletNode = airLoop.zoneSplitter().lastOutletModelObject()->cast<Node>();
  EXPECT_FALSE(coilCoolingCooledBeam.addToNode(inletNode));
  EXPECT_EQ((unsigned)5, airLoop.demandComponents().size());

  // make a plant loop
  PlantLoop hotWaterPlant(model);

  // find the empty plant node to add the coil
  Node node = hotWaterPlant.demandSplitter().lastOutletModelObject()->cast<Node>();

  // add the coil
  EXPECT_TRUE(coilCoolingCooledBeam.addToNode(node));
  EXPECT_EQ((unsigned)7, hotWaterPlant.demandComponents().size());

  supplyOutletNode = hotWaterPlant.supplyOutletNode();
  EXPECT_FALSE(coilCoolingCooledBeam.addToNode(supplyOutletNode));
  EXPECT_EQ((unsigned)5, hotWaterPlant.supplyComponents().size());

  auto testObjectClone = coilCoolingCooledBeam.clone(model).cast<CoilCoolingCooledBeam>();
  node = hotWaterPlant.demandOutletNode();

  EXPECT_TRUE(testObjectClone.addToNode(node));
  EXPECT_EQ((unsigned)9, hotWaterPlant.demandComponents().size());

  // disconnect the coil and check if it works
  coilCoolingCooledBeam.disconnect();
  /* get a vector of demand equipment on the plantloop called hotwaterPlant,
     we know that plantloop.demandcomponents() returns a variable type std::vector<ModelObject>
     and we want to make sure that the vector is empty, because we have removed the coil */

  // variable type variable name = plant loop class object function(), no argument goes back to default
  std::vector<ModelObject> hotWaterDemandComponents = hotWaterPlant.demandComponents();
  EXPECT_EQ(hotWaterDemandComponents.size(), 0);
}
