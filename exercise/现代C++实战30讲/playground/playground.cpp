#include "playground.h"

namespace playground
{
	// 智能指针
	template<typename T>
	class smart_ptr
	{
	public:
		explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {
		}

		~smart_ptr() {
			delete ptr_;
		}

		T* get() const {
			return ptr_;
		}

		T& operator*() const {
			return *ptr_;
		}

		T* operator->() const {
			return ptr_;
		}

		explicit operator bool() const {
			return ptr_;
		}

	private:
		T* ptr_;
	};

	void main() {

	}
}
