//
// Created by sevastian on 28.11.23.
//

#include "../include/CDRWriterImpl.h"

void CDRWriterImpl::writeCDR(const CallInfo &callInfo) {
    if (fileStream.fail()) {
        BOOST_LOG_TRIVIAL(warning) << "CDRWriterImpl: can not write CDR - file stream is not opened";
        return;
    }
    fileStream << callInfo.callId.id << ";" << callInfo.number.number << ";" << callInfo.incomeDt.time << ";" << callInfo.operatorId.id << ";" << callInfo.operatorAnswerDt.time 
               << ";" << callInfo.endDt.time << ";" << callInfo.duration.duration << ";" << callInfo.status << std::endl;
    fileStream.flush();
    BOOST_LOG_TRIVIAL(info) << "CDRWriterImpl: writed CDR for number " << callInfo.number.number << " with status " << callInfo.status;
}
