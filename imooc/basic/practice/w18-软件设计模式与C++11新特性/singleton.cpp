#include "head.h"

namespace singleton {

// 饿汉式
class HungrySingleton {
  private:
	static HungrySingleton *object;
  protected:
	HungrySingleton() = default;
	HungrySingleton(const HungrySingleton &other) {
	  *this = other;
	}
  public:
	static HungrySingleton *getInstance() {
	  return object;
	}
};
HungrySingleton *HungrySingleton::object = new HungrySingleton;

// 懒汉式
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
class LazySingleton {
  private:
	static LazySingleton *object;
  protected:
	LazySingleton() = default;
	LazySingleton(const LazySingleton &other) {
	  *this = other;
	}
  public:
	static LazySingleton *getInstance() {
	  if (object == nullptr) {
		pthread_mutex_lock(&lock);
		if (object == NULL) {
		  object = new LazySingleton;
		}
		pthread_mutex_lock(&lock);
	  }
	  return object;
	}
};
LazySingleton *LazySingleton::object = nullptr;

void test() {

}
}
