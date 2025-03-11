#ifndef TAMANDU_CONTEXT_HPP
#define TAMANDU_CONTEXT_HPP

class TamanduContext {
 public:
  explicit TamanduContext(int id) : id(id) {}

  auto getId() const -> int { return id; }

 private:
  int id;
};

#endif  // TAMANDU_CONTEXT_HPP
