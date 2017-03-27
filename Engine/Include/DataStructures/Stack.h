#pragma once

#include <cassert>
#include "Globals.h"

using namespace std;

namespace Engine {
	template <class T>
	class EXPORT Stack
	{
	public:
		Stack(uint size) {

			if (size < 1) { throw std::exception("stack size must be a value greater than 0."); }

			m_data = new T[size];
			m_size = size;
			m_head = 0;
		}

		~Stack() {
			delete[] m_data;
		}

		inline void Push(const T data) {
			if (IsFull()) { throw std::exception("stack overflow"); }
			m_data[m_head++] = data;
		}

		T Pop() {
			if (IsEmpty()) { throw std::exception("stack underflow"); }
			m_head--;
			T result = m_data[m_head];
			return result;
		}

		inline void Clear() {
			m_head = 0;
		}

		inline bool IsFull() {
			return m_head >= m_size;
		}

		inline bool IsEmpty() {
			return m_head < 1;
		}

		inline int Top() {
			return m_head;
		}

		inline int GetSize() {
			return m_size;
		}

	private:
		T* m_data;
		uint m_size;
		int m_head;
	};

}