#include "YMMYApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
YMMYApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

YMMYApp::YMMYApp(InputParameters parameters) : MooseApp(parameters)
{
  YMMYApp::registerAll(_factory, _action_factory, _syntax);
}

YMMYApp::~YMMYApp() {}

void
YMMYApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"YMMYApp"});
  Registry::registerActionsTo(af, {"YMMYApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
YMMYApp::registerApps()
{
  registerApp(YMMYApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
YMMYApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YMMYApp::registerAll(f, af, s);
}
extern "C" void
YMMYApp__registerApps()
{
  YMMYApp::registerApps();
}
