#ifndef CTHREADQUEUE
#define CTHREADQUEUE
#include<condition_variable>
#include<cstddef>
#include<queue>
#include<mutex>

namespace nTool
{
	template<class T>
	class CThreadQueue
	{
		std::condition_variable push_;
		std::mutex pushMut_;
		std::queue<T> queue_;
	public:
		template<class ... Args>
		void emplace(Args &&...);
		inline std::size_t size() const noexcept
		{
			return queue_.size();
		}
		T wait_and_pop();
	};
}

#include"CThreadQueueT.cpp"

#endif