#ifndef TAMANDU_CONTEXT_HPP
#define TAMANDU_CONTEXT_HPP

class TamanduContext {
public:
  explicit TamanduContext(int id) : id(id) {}

  int getId() const { return id; }

private:
  int id;
};

#endif // TAMANDU_CONTEXT_HPP
