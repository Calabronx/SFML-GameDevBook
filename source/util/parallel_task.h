#pragma once
#ifndef PARALLELTASK_HPP
#define PARALLELTASK_HPP

#include<SFML/Graphics.hpp>

class ParallelTask
{
public:
								ParallelTask();
	void				execute();
	bool				isFinished();
	float				getCompletion();

private:
	void				runTask();

private:
	sf::Thread			mThread;
	bool				mFinished;
	sf::Clock			mElapsedTime;
	sf::Mutex			mMutex;

};
#endif // !PARALLELTASK_HPP

