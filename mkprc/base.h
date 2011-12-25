#pragma once
class base 
{
	public:
		base(const int);
		virtual ~base();
		virtual void create() = 0;
		void sleepWell(const int);

	protected:
		const int mVar;
};
