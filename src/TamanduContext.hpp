#ifndef TAMANDU_CONTEXT_H
#define TAMANDU_CONTEXT_H

class TamanduContext {
public:
  TamanduContext(int id) : id(id) {}

  int getId() const { return id; }

private:
  int id;
};

#endif // TAMANDU_CONTEXT_H
