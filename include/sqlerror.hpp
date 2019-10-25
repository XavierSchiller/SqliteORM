#include <stdexcept>
namespace xsqlite3 {
class openerr : public std::exception {
  std::string errmsg;

public:
  openerr(std::string err) { this->errmsg = err; }
  const char *what() const noexcept override { return errmsg.c_str(); }
};
} // namespace xsqlite3