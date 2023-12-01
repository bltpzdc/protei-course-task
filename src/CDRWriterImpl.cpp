//
// Created by sevastian on 28.11.23.
//

#include "../include/CDRWriterImpl.h"

void CDRWriterImpl::writeCDR(const CallInfo &callInfo) {
    if (fileStream.fail()) {
        BOOST_LOG_TRIVIAL(warning) << "CDRWriterImpl: can not write CDR - file stream is not opened";
        return;
    }

    char inT[20];
    char opT[20] = {0};
    char endT[20];    
    toLocalTime(inT, callInfo.incomeDt.time);
    if (callInfo.operatorAnswerDt.time != 0) toLocalTime(opT, callInfo.operatorAnswerDt.time);
    else opT[0] = '0';
    toLocalTime(endT, callInfo.endDt.time);

    fileStream << callInfo.callId.id << ";" << callInfo.number.number << ";" << inT << ";" << callInfo.operatorId.id << ";" << opT
               << ";" << endT << ";" << callInfo.duration.duration << ";" << callInfo.status << std::endl;
    fileStream.flush();
    BOOST_LOG_TRIVIAL(info) << "CDRWriterImpl: writed CDR for number " << callInfo.number.number << " with status " << callInfo.status;
}

void CDRWriterImpl::toLocalTime(char (&buff)[], std::time_t t) {
    struct tm *localTime = localtime(&t);   
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localTime);
}
