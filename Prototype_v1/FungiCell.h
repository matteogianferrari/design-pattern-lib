#ifndef FUNGICELL_H
#define FUNGICELL_H

#include <mutex>
#include <string>
#include "ICell.h"

class FungiCell:
    public ICell
{
public:
    FungiCell(std::string& fungi);
    FungiCell(FungiCell& cell);

    ~FungiCell() override;

    ICell* clone(void) override;
    void print(std::ostream& os) override;

    void absorb(void);

private:
    std::mutex _mutex;
    std::string _fungi;
};

#endif  //PLANTCELL_H