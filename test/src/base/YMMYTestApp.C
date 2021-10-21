//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "YMMYTestApp.h"
#include "YMMYApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
YMMYTestApp::validParams()
{
  InputParameters params = YMMYApp::validParams();
  return params;
}

YMMYTestApp::YMMYTestApp(InputParameters parameters) : MooseApp(parameters)
{
  YMMYTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

YMMYTestApp::~YMMYTestApp() {}

void
YMMYTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  YMMYApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"YMMYTestApp"});
    Registry::registerActionsTo(af, {"YMMYTestApp"});
  }
}

void
YMMYTestApp::registerApps()
{
  registerApp(YMMYApp);
  registerApp(YMMYTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
YMMYTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YMMYTestApp::registerAll(f, af, s);
}
extern "C" void
YMMYTestApp__registerApps()
{
  YMMYTestApp::registerApps();
}
