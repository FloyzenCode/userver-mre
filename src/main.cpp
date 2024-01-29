#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component.hpp>
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/server/handlers/tests_control.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/utils/daemon_run.hpp>

#include "handlers/hello/hello.hpp"
#include "handlers/bye/bye.hpp"

auto main(int argc, char* argv[]) -> int {
  const auto component_list = userver::components::MinimalServerComponentList()
                                  .Append<http_service::hello::Hello>()
                                  .Append<http_service::bye::Bye>();
  return userver::utils::DaemonMain(argc, argv, component_list);
}
