s32 mlTsbRequest(u16 bank, u16 code, s32* aRtpc) {
    CSE_REQP reqp = {};
    SoundEvent* pTSB;

    while (1) {
        pTSB = mlTsbGetDataAdrs(bank, code);
        mlTsbSetToReqp(&reqp, pTSB, bank);
        reqp.note += aRtpc[1];
        reqp.id1 += aRtpc[2];
        reqp.id2 += aRtpc[3];
        reqp.prio += aRtpc[4];
        reqp.vol += aRtpc[5];
        reqp.pan += aRtpc[6];
        reqp.pitch += aRtpc[7];
        reqp.kofftime += aRtpc[8];
        reqp.limit += aRtpc[9];
        switch (pTSB->cmd) {
            case 0:
            case 4:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            default:
                break;
            case 6:
                mlTsbCreateEcho(bank, code, aRtpc);
                break;
            case 7:
                mlTsbStopEcho(bank, code);
                break;
            case 1:
                mlTsbKeyOn(pTSB, &reqp, bank, pTSB->prog + aRtpc[0]);
                break;
            case 2:
                mlSeKeyoff(&reqp);
                break;
            case 3:
                mlSeStop(&reqp);
                break;
            case 5:
                mlSeSetLfo(&reqp,pTSB->param0,pTSB->param1, pTSB->param2, pTSB->param3);
                break;
            }
        if (((pTSB->link) != 0xFFFF) && ( pTSB->link != code)) {
            code = (u16)pTSB->link;
        } else {
            break;
        }
    }
    return 0;
}
