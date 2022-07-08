char *
tagicon(Monitor *m, int tag)
{
	int tagindex = tag + NUMTAGS * m->num;
	if (tagindex >= LENGTH(tagicons[DEFAULT_TAGS]))
		tagindex = tagindex % LENGTH(tagicons[DEFAULT_TAGS]);
	if (m->alttag)
		return tagicons[ALTERNATIVE_TAGS][tagindex];
	return tagicons[DEFAULT_TAGS][tagindex];
}

