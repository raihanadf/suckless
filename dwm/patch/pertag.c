struct Pertag {
	unsigned int curtag, prevtag; /* current and previous tag */
	int nmasters[NUMTAGS + 1]; /* number of windows in master area */
	const Layout *ltidxs[NUMTAGS + 1][2]; /* matrix of tags and layouts indexes  */
	float mfacts[NUMTAGS + 1]; /* mfacts per tag */
	unsigned int sellts[NUMTAGS + 1]; /* selected layouts */
	Client *prevzooms[NUMTAGS + 1]; /* store zoom information */
	int enablegaps[NUMTAGS + 1];
	unsigned int gaps[NUMTAGS + 1];
};

void
pertagview(const Arg *arg)
{
	int i;
	unsigned int tmptag;
	if (arg->ui & TAGMASK) {
		selmon->pertag->prevtag = selmon->pertag->curtag;
		selmon->tagset[selmon->seltags] = arg->ui & TAGMASK;
		if (arg->ui == ~0)
			selmon->pertag->curtag = 0;
		else {
			for (i = 0; !(arg->ui & 1 << i); i++) ;
			selmon->pertag->curtag = i + 1;
		}
	} else {
		tmptag = selmon->pertag->prevtag;
		selmon->pertag->prevtag = selmon->pertag->curtag;
		selmon->pertag->curtag = tmptag;
	}
	selmon->nmaster = selmon->pertag->nmasters[selmon->pertag->curtag];
	selmon->mfact = selmon->pertag->mfacts[selmon->pertag->curtag];
	selmon->sellt = selmon->pertag->sellts[selmon->pertag->curtag];
	selmon->lt[selmon->sellt] = selmon->pertag->ltidxs[selmon->pertag->curtag][selmon->sellt];
	selmon->lt[selmon->sellt^1] = selmon->pertag->ltidxs[selmon->pertag->curtag][selmon->sellt^1];

	selmon->gappoh = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff) >> 0;
	selmon->gappov = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff00) >> 8;
	selmon->gappih = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff0000) >> 16;
	selmon->gappiv = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff000000) >> 24;

}

