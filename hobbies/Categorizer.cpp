#include <QDebug>
#include <QHash>
#include <QStringList>
#include <algorithm>
#include <stdexcept>
#include <utility>

/*
 * GPLed (v3)
 * Just came out of my thoughts.
 * So use it as in definitions(.h) and implementations(.cpp), not like this!
 * Machine learning? I'm trying to love it.
 * I may will use this for my projects :P
 * Hamidreza Davoodi
 */

namespace Global {
enum eRate
{
    Unknown = -1,
    White,
    Gray,
    Dark
};
}


class Categorizer
{

private:
    struct WordValue
    {
        int Repeats;
        Global::eRate Type;
    };

public:
    Categorizer() {}
    Categorizer(const Categorizer &other) {
        m_Table = other.m_Table;
    }

    void setToTable(const QString &word)
    {
        auto itr = m_Table.find(word);

        if ( itr != m_Table.end() ) {
            ++ itr.value().Repeats;
        }
        else {
            WordValue value = { 1, validateWord(word) };
            m_Table.insert(word, value);
        }

    }

    Global::eRate validateWord(const QString &word)
    { return Global::Unknown; }


    void printOut() const
    {
        for( auto itr = m_Table.begin(); itr != m_Table.end(); ++ itr  )
            qDebug() << itr.key() << ":" << itr.value().Repeats;
    }


    QHash<QString, std::pair<WordValue, WordValue> > intersects(const Categorizer &other) const
    {
        if ( &other == this )
            throw std::runtime_error("Same categorizer!");

        QHash<QString, std::pair<WordValue, WordValue> > hash;
        for ( auto itr = other.m_Table.constBegin(); itr != other.m_Table.constEnd(); ++ itr )
        {
            auto first = m_Table.find(itr.key());
            if (first != m_Table.end())
                hash.insert( itr.key(), std::make_pair(first.value(), itr.value()) );
        }
        return hash;
    }

private:
    QHash <QString, WordValue > m_Table;
};


namespace Helper {

void showIntersects( const Categorizer &left, const Categorizer &right )
{
    auto &&intersects = left.intersects(right);
    for ( auto itr = intersects.begin(); itr != intersects.end(); ++ itr )
        qDebug() << itr.key() <<itr.value().first.Repeats << itr.value().second.Repeats;
}

QStringList tokenizer(const QString &words)
{
    auto tokens = words.simplified().split(" ", QString::SkipEmptyParts );
    return tokens;
}


Categorizer make_categorizer(const QString &words)
{
    Categorizer cat;
    auto &&tokens = tokenizer(words);
    for ( auto &&word : tokens )
        cat.setToTable(word);

    return cat;
}


}


int main(int argc, char *argv[])
{
    auto cat1 = Helper::make_categorizer("You will find The Essential Guide to HTML5 and CSS3 Web Design invaluable \
            at any stage of your career, with its mixture of practical tutorials and reference material.\
            Beginners will quickly pick up the basics, while more experienced web designers and developers \
            will keep returning to the book again and again to read up on techniques they may not have used  \
            for a while, or to look up properties, attributes and other details. This book is destined to become\
            a close friend, adopting a permanent place on your desk. " );

    auto cat2 = Helper::make_categorizer(" The Essential Guide to HTML5 and CSS3 Web Design starts off \
            with a brief introduction to the web and web design, before diving \
            straight in to HTML5 and CSS3 basics, reusing code, and other best practices you can adopt\
            The book then focuses on the most important areas of a successful web site: typography,  \
            images, navigation, tables, layouts, forms and feedback (including ready-made PHP scripts) and browser quirks, hacks and bugs. " );


    cat1.printOut();
    cat2.printOut();
    Helper::showIntersects(cat1, cat2);
    
    return 0;
}

