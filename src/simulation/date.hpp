

struct date
{
    enum class Season {SPRING, SUMMER, AUTUM, WINTER, NUMBER_OF_SEASONS};
    
	int m_year;
	Season m_season;

	void operator++()
	{
		this->m_season =  Season(((int)m_season + 1) % 4);
		
		if((int)this->m_season + 1 == 0)
			m_year++;
	}
};