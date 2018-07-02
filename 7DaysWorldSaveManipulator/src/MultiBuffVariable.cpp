#include "MultiBuffVariable.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

MultiBuffVariable::MultiBuffVariable() {}
MultiBuffVariable::~MultiBuffVariable() {}

int MultiBuffVariable::read(BinaryMemoryReader &reader) {
    reader.read<int>(multiBuffVariableVersion);
    VersionCheck::checkVersion(multiBuffVariableVersion, MULTI_BUFF_VARIABLE_VER, MULTI_BUFF_VARIABLE);

    reader.read<float>(unknownQ);
    reader.read<float>(unknownJ);
    reader.read<float>(unknownS);
    reader.read<float>(unknownC);

    return 0;
}

void MultiBuffVariable::write(BinaryMemoryWriter &writer) const {
    writer.write<int>(multiBuffVariableVersion);
    writer.write<float>(unknownQ);
    writer.write<float>(unknownJ);
    writer.write<float>(unknownS);
    writer.write<float>(unknownC);
}
