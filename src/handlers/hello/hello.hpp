#pragma once
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/http_handler_base.hpp>
#include <userver/utils/daemon_run.hpp>

namespace http_service::hello {
class Hello final : public userver::server::handlers::HttpHandlerBase {
 public:
  static constexpr std::string_view kName = "handler-hello-sample";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest&,
      userver::server::request::RequestContext&) const override;
};
}  // namespace http_service::hello
