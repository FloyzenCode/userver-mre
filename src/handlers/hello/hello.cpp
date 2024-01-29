#include "hello.hpp"

std::string http_service::hello::Hello::HandleRequestThrow(
    const userver::server::http::HttpRequest&,
    userver::server::request::RequestContext&) const {
  return "Hello world!\n";
}
