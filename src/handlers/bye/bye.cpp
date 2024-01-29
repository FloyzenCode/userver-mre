#include "bye.hpp"

std::string http_service::bye::Bye::HandleRequestThrow(
    const userver::server::http::HttpRequest&,
    userver::server::request::RequestContext&) const {
  return "Bye-bye!\n";
}
