#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class   Brain
{
    public:
        Brain();
        Brain(Brain& brain);
        Brain& operator=(const Brain& brain);
        ~Brain();
        std::string ideas[100];
        void setIdeas(const Brain *otherBrain);
};

#endif