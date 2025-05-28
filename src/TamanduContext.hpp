#ifndef DATA_ABSTRACT_HPP
#define DATA_ABSTRACT_HPP

#include <atomic>
#include <cstdlib>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace Tamandu {

template <class T> class Context {
public:
  Context(std::string name);
  Context(std::string name, T value);
  virtual ~Context();

  T    get();
  void set(T data);
  void set(std::string data);

  std::string getName();
  std::string getString(std::string ctrl);

protected:
  std::string name;

  std::string demangle(const char *mangled) {
    int                                       status;
    std::unique_ptr<char[], void (*)(void *)> result(
        abi::__cxa_demangle(mangled, 0, 0, &status), std::free);
    return result.get() ? std::string(result.get()) : "error occurred";
  };

private:
  std::atomic<T>       *data;
  std::atomic<uint32_t> time_last_change; // Tempo de execução em que o dado foi
                                          // alterado pela última vez
  std::atomic<uint32_t>
      stream_interval; // Intervalo que o stream do atributo será feito
  std::atomic<uint32_t>
      stream_time;     // momento em que o stream do atributo deve ser feito
};

template <class T> Context<T>::Context(std::string name) {
  ESP_LOGD(name.c_str(),
           "Criando *dado do tipo %s, variavel inicializada com: %s",
           demangle(typeid(*this).name()).c_str(),
           std::string(std::to_string(T())).c_str());

  this->dataStorage = dataStorage->getInstance();
  this->dataManager = dataManager->getInstance();

  this->data = new std::atomic<T>();
  this->time_last_change.store(0, std::memory_order_release);
  this->stream_interval.store(0, std::memory_order_release);
  this->stream_time.store(0, std::memory_order_release);
}

template <class T> Context<T>::Context(std::string name, T value) {
  ESP_LOGD(name.c_str(),
           "Criando *dado do tipo %s, com valor inicial definido: %s",
           demangle(typeid(*this).name()).c_str(),
           std::string(std::to_string(value)).c_str());

  this->dataStorage = dataStorage->getInstance();
  this->dataManager = dataManager->getInstance();

  this->data = new std::atomic<T>(value);
  this->time_last_change.store(0, std::memory_order_release);
  this->stream_interval.store(0, std::memory_order_release);
  this->stream_time.store(0, std::memory_order_release);
}

template <class T> Context<T>::~Context() {
  ESP_LOGD(this->name.c_str(), "Destruindo dado do tipo %s",
           demangle(typeid(*this).name()).c_str());
  delete this->data;
}

template <class T> std::string Context<T>::getName() { return this->name; }

template <class T> T Context<T>::get() {
  // retorna o valor do dado
  return this->data->load(std::memory_order_acquire);
}

template <class T> std::string Context<T>::getString(std::string ctrl) {
  // retorna o valor do dado
  // Create an output string stream
  // std::ostringstream streamObj;
  // Add data to stream
  // streamObj << this->data->load(std::memory_order_acquire);
  // Get string from output string stream
  // std::string strObj = streamObj.str();
  // streamObj.str("");
  double num = this->data->load(std::memory_order_acquire);
  char   buffer[64];
  memset(buffer, 0, sizeof(buffer));
  snprintf(buffer, sizeof(buffer), "%g", num);
  std::string strObj(buffer);
  return strObj;
}

template <class T> void Context<T>::set(T data) {
  // seta o valor do dado
  this->data->store(data, std::memory_order_release);
  uint32_t last_change = xTaskGetTickCount() * portTICK_PERIOD_MS;
  if(this->stream_interval.load(std::memory_order_acquire) != 0)
    this->time_last_change.store(last_change, std::memory_order_release);
}

template <class T> void Context<T>::set(std::string data) {
  double num = std::stod(data);
  this->data->store(num, std::memory_order_release);
  uint32_t last_change = xTaskGetTickCount() * portTICK_PERIOD_MS;
  if(this->stream_interval.load(std::memory_order_acquire) != 0)
    this->time_last_change.store(last_change, std::memory_order_release);

  double Testnum = this->data->load(std::memory_order_acquire);
  char   buffer[64];
  memset(buffer, 0, sizeof(buffer));
  snprintf(buffer, sizeof(buffer), "%g", Testnum);
  std::string strObj(buffer);
  ESP_LOGD(this->name.c_str(), "Confirmando dado salvo: %s", strObj.c_str());
}
} // namespace Tamandu

#endif