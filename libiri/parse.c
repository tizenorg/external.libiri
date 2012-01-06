/*
 * libiri: An IRI/URI/URL parsing library
 * @(#) $Id$
 */

/*
 * Copyright (c) 2005, 2008 Mo McRoberts.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. The names of the author(s) of this software may not be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * AUTHORS OF THIS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*

The following code was added by Samsung Electronics.

--- a/libiri/parse.c
+++ b/libiri/parse.c
@@ -59,6 +59,7 @@ iri__hexnibble(char c)
        {
                return c - 'a' + 10;
        }
+    return 0;
 }
 
 static inline const char *
@@ -130,6 +131,7 @@ iri__allocbuf(const char *src, size_t *len)
                *len = (src - c) + 1 + sc + ((sc + 1) * (sizeof(char *) + 7));
                *len += (7 * 11);
        }
+    *len = 9999; // FIXME: DIRTY HACK THAT USUALLY WORKS... UNTIL IRI IS NOT TO
        return (char *) calloc(1, *len);
 }



License of the above code is Apache License


    Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.

                                 Apache License
                           Version 2.0, January 2004
                        http://www.apache.org/licenses/

   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION

   1. Definitions.

      "License" shall mean the terms and conditions for use, reproduction,
      and distribution as defined by Sections 1 through 9 of this document.

      "Licensor" shall mean the copyright owner or entity authorized by
      the copyright owner that is granting the License.

      "Legal Entity" shall mean the union of the acting entity and all
      other entities that control, are controlled by, or are under common
      control with that entity. For the purposes of this definition,
      "control" means (i) the power, direct or indirect, to cause the
      direction or management of such entity, whether by contract or
      otherwise, or (ii) ownership of fifty percent (50%) or more of the
      outstanding shares, or (iii) beneficial ownership of such entity.

      "You" (or "Your") shall mean an individual or Legal Entity
      exercising permissions granted by this License.

      "Source" form shall mean the preferred form for making modifications,
      including but not limited to software source code, documentation
      source, and configuration files.

      "Object" form shall mean any form resulting from mechanical
      transformation or translation of a Source form, including but
      not limited to compiled object code, generated documentation,
      and conversions to other media types.

      "Work" shall mean the work of authorship, whether in Source or
      Object form, made available under the License, as indicated by a
      copyright notice that is included in or attached to the work
      (an example is provided in the Appendix below).

      "Derivative Works" shall mean any work, whether in Source or Object
      form, that is based on (or derived from) the Work and for which the
      editorial revisions, annotations, elaborations, or other modifications
      represent, as a whole, an original work of authorship. For the purposes
      of this License, Derivative Works shall not include works that remain
      separable from, or merely link (or bind by name) to the interfaces of,
      the Work and Derivative Works thereof.

      "Contribution" shall mean any work of authorship, including
      the original version of the Work and any modifications or additions
      to that Work or Derivative Works thereof, that is intentionally
      submitted to Licensor for inclusion in the Work by the copyright owner
      or by an individual or Legal Entity authorized to submit on behalf of
      the copyright owner. For the purposes of this definition, "submitted"
      means any form of electronic, verbal, or written communication sent
      to the Licensor or its representatives, including but not limited to
      communication on electronic mailing lists, source code control systems,
      and issue tracking systems that are managed by, or on behalf of, the
      Licensor for the purpose of discussing and improving the Work, but
      excluding communication that is conspicuously marked or otherwise
      designated in writing by the copyright owner as "Not a Contribution."

      "Contributor" shall mean Licensor and any individual or Legal Entity
      on behalf of whom a Contribution has been received by Licensor and
      subsequently incorporated within the Work.

   2. Grant of Copyright License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      copyright license to reproduce, prepare Derivative Works of,
      publicly display, publicly perform, sublicense, and distribute the
      Work and such Derivative Works in Source or Object form.

   3. Grant of Patent License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      (except as stated in this section) patent license to make, have made,
      use, offer to sell, sell, import, and otherwise transfer the Work,
      where such license applies only to those patent claims licensable
      by such Contributor that are necessarily infringed by their
      Contribution(s) alone or by combination of their Contribution(s)
      with the Work to which such Contribution(s) was submitted. If You
      institute patent litigation against any entity (including a
      cross-claim or counterclaim in a lawsuit) alleging that the Work
      or a Contribution incorporated within the Work constitutes direct
      or contributory patent infringement, then any patent licenses
      granted to You under this License for that Work shall terminate
      as of the date such litigation is filed.

   4. Redistribution. You may reproduce and distribute copies of the
      Work or Derivative Works thereof in any medium, with or without
      modifications, and in Source or Object form, provided that You
      meet the following conditions:

      (a) You must give any other recipients of the Work or
          Derivative Works a copy of this License; and

      (b) You must cause any modified files to carry prominent notices
          stating that You changed the files; and

      (c) You must retain, in the Source form of any Derivative Works
          that You distribute, all copyright, patent, trademark, and
          attribution notices from the Source form of the Work,
          excluding those notices that do not pertain to any part of
          the Derivative Works; and

      (d) If the Work includes a "NOTICE" text file as part of its
          distribution, then any Derivative Works that You distribute must
          include a readable copy of the attribution notices contained
          within such NOTICE file, excluding those notices that do not
          pertain to any part of the Derivative Works, in at least one
          of the following places: within a NOTICE text file distributed
          as part of the Derivative Works; within the Source form or
          documentation, if provided along with the Derivative Works; or,
          within a display generated by the Derivative Works, if and
          wherever such third-party notices normally appear. The contents
          of the NOTICE file are for informational purposes only and
          do not modify the License. You may add Your own attribution
          notices within Derivative Works that You distribute, alongside
          or as an addendum to the NOTICE text from the Work, provided
          that such additional attribution notices cannot be construed
          as modifying the License.

      You may add Your own copyright statement to Your modifications and
      may provide additional or different license terms and conditions
      for use, reproduction, or distribution of Your modifications, or
      for any such Derivative Works as a whole, provided Your use,
      reproduction, and distribution of the Work otherwise complies with
      the conditions stated in this License.

   5. Submission of Contributions. Unless You explicitly state otherwise,
      any Contribution intentionally submitted for inclusion in the Work
      by You to the Licensor shall be under the terms and conditions of
      this License, without any additional terms or conditions.
      Notwithstanding the above, nothing herein shall supersede or modify
      the terms of any separate license agreement you may have executed
      with Licensor regarding such Contributions.

   6. Trademarks. This License does not grant permission to use the trade
      names, trademarks, service marks, or product names of the Licensor,
      except as required for reasonable and customary use in describing the
      origin of the Work and reproducing the content of the NOTICE file.

   7. Disclaimer of Warranty. Unless required by applicable law or
      agreed to in writing, Licensor provides the Work (and each
      Contributor provides its Contributions) on an "AS IS" BASIS,
      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
      implied, including, without limitation, any warranties or conditions
      of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
      PARTICULAR PURPOSE. You are solely responsible for determining the
      appropriateness of using or redistributing the Work and assume any
      risks associated with Your exercise of permissions under this License.

   8. Limitation of Liability. In no event and under no legal theory,
      whether in tort (including negligence), contract, or otherwise,
      unless required by applicable law (such as deliberate and grossly
      negligent acts) or agreed to in writing, shall any Contributor be
      liable to You for damages, including any direct, indirect, special,
      incidental, or consequential damages of any character arising as a
      result of this License or out of the use or inability to use the
      Work (including but not limited to damages for loss of goodwill,
      work stoppage, computer failure or malfunction, or any and all
      other commercial damages or losses), even if such Contributor
      has been advised of the possibility of such damages.

   9. Accepting Warranty or Additional Liability. While redistributing
      the Work or Derivative Works thereof, You may choose to offer,
      and charge a fee for, acceptance of support, warranty, indemnity,
      or other liability obligations and/or rights consistent with this
      License. However, in accepting such obligations, You may act only
      on Your own behalf and on Your sole responsibility, not on behalf
      of any other Contributor, and only if You agree to indemnify,
      defend, and hold each Contributor harmless for any liability
      incurred by, or claims asserted against, such Contributor by reason
      of your accepting any such warranty or additional liability.

   END OF TERMS AND CONDITIONS

   APPENDIX: How to apply the Apache License to your work.

      To apply the Apache License to your work, attach the following
      boilerplate notice, with the fields enclosed by brackets "[]"
      replaced with your own identifying information. (Don't include
      the brackets!)  The text should be enclosed in the appropriate
      comment syntax for the file format. We also recommend that a
      file or class name and description of purpose be included on the
      same "printed page" as the copyright notice for easier
      identification within third-party archives.

   Copyright [yyyy] [name of copyright owner]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.


*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>

#include "p_libiri.h"

#undef ALIGNMENT
#define ALIGNMENT 8
#undef ALIGN
#define _ALIGN(x) ((((x)+(ALIGNMENT-1))&~(ALIGNMENT-1)))
#define ALIGN(x) (char *) _ALIGN((size_t) x)

static inline int
iri__hexnibble(char c)
{
	if(c >= '0' && c <= '9')
	{
		return c - '0';
	}
	if(c >= 'A' && c <= 'F')
	{
		return c - 'A' + 10;
	}
	if(c >= 'a' && c <= 'f')
	{
		return c - 'a' + 10;
	}
    return 0;
}

static inline const char *
iri__copychar(char **dest, const char *src)
{
	**dest = *src;
	(*dest)++;
	src++;
	return src;
}

/* TODO: Punycode decoding for the host part */
static inline const char *
iri__copychar_decode(char **dest, const char *src, int convert_space)
{
	unsigned char *p = (unsigned char *) (*dest);
	
	if(1 == convert_space && '+' == *src)
	{
		**dest = ' ';
	}
	else if('%' == *src)
	{
		if(0 == isxdigit(src[1]) || 0 == isxdigit(src[2]))
		{
			/* TODO: Deal with %u<nnnn> non-standard encoding - be liberal in
			 * what you accept, etc.
			 */
			**dest = '%';
		}
		else
		{
			*p = (iri__hexnibble(src[1]) << 4) | iri__hexnibble(src[2]);
			src += 2;
		}
	}
	else
	{
		**dest = *src;
	}
	src++;
	(*dest)++;
	return src;
}

static inline char *
iri__allocbuf(const char *src, size_t *len)
{
	size_t sc;
	const char *p, *c;
	
	/* Calculate the size of the buffer required to hold a decoded version of
	 * src, including enough breathing space for null bytes.
	 */
	/* XXX: This is way too much; we need to actually count it */
	*len = (strlen(src) * 4) + 16;
	/* Determine how much space we need for the scheme list */
	if(NULL != (c = strchr(src, ':')))
	{
		sc = 1;
		for(p = src; p < c; p++)
		{
			if(*p == '+')
			{
				sc++;
			}
		}
		/* Ensure we can align each element on an 8-byte boundary */
		*len = (src - c) + 1 + sc + ((sc + 1) * (sizeof(char *) + 7));
		*len += (7 * 11);
	}
    *len = 9999; // FIXME: DIRTY HACK THAT USUALLY WORKS... UNTIL IRI IS NOT TOO LONG
	return (char *) calloc(1, *len);
}

iri_t *
iri_parse(const char *src)
{
	iri_t *p;
	char *bufstart, *endp, *bufp, **sl;
	const char *at, *colon, *slash, *t;
	size_t buflen, sc, cp;
	
	if(NULL == (p = (iri_t *) calloc(1, sizeof(iri_t))))
	{
		return NULL;
	}
	if(NULL == (bufstart = iri__allocbuf(src, &buflen)))
	{
		free(p);
		return NULL;
	}
	p->base = bufp = bufstart;
	p->nbytes = buflen;
	at = strchr(src, '@');
	slash = strchr(src, '/');
	colon = strchr(src, ':');
	if(slash && colon && slash < colon)
	{
		/* We can disregard the colon if a slash appears before it */
		colon = NULL;
	}
	if(colon && !at)
	{
		/* Definitely a scheme */
		bufp = ALIGN(bufp);
		p->iri.scheme = bufp;
		while(*src && *src != ':')
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
		src++;
		/* src[0-1] SHOULD == '/' */
		if(src[0] == '/') src++;
		if(src[0] == '/') src++;
	}
	else if(colon && at && colon < at)
	{
		fprintf(stderr, "Colon occurs before at\n");
		/* This could be scheme://user[;auth][:password]@host or [scheme:]user[;auth][:password]@host (urgh) */
		if(colon[1] == '/' && colon[2] == '/' && colon[3] != '/')
		{
			bufp = ALIGN(bufp);
			p->iri.scheme = bufp;
			while(*src && *src != ':')
			{
				src = iri__copychar_decode(&bufp, src, 0);
			}
			*bufp = 0;
			bufp++;
			src++;
			/* src[0-1] SHOULD == '/' */
			for(; *src == '/'; src++);
			bufp = ALIGN(bufp);
			p->iri.user = bufp;
			fprintf(stderr, "Found user\n");
		}
		else
		{
			fprintf(stderr, "Matched scheme\n");
			bufp = ALIGN(bufp);
			p->iri.scheme = bufp;
		}
		while(*src && *src != ':' && *src != '@' && *src != ';')
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
		if(*src == ';')
		{
			/* Following authentication parameters */
			src++;
			bufp = ALIGN(bufp);
			p->iri.auth = bufp;
			while(*src && *src != ':' && *src != '@')
			{
				/* Don't decode, so it can be extracted properly */
				src = iri__copychar(&bufp, src);
			}
			*bufp = 0;
			bufp++;
		}
		if(*src == ':')
		{
			/* Following password data */
			src++;
			bufp = ALIGN(bufp);
			p->iri.password = bufp;
			while(*src && *src != ':' && *src != '@')
			{
				src = iri__copychar_decode(&bufp, src, 0);
			}
			*bufp = 0;
			bufp++;
			if(*src == ':')
			{
				src++;
				/* It was actually scheme:user:auth@host */
				p->iri.user = p->iri.auth;
				bufp = ALIGN(bufp);
				p->iri.password = bufp;
				while(*src && *src != '@')
				{
					src = iri__copychar_decode(&bufp, src, 0);
				}
				*bufp = 0;
				bufp++;
			}
		}
		if(!*src)
		{
			/* No host part */
			return p;
		}
		if(*src == '@')
		{
			src++;
		}
	}
	else if(at)
	{
		/* user[;auth]@host[/path...] */
		bufp = ALIGN(bufp);
		p->iri.user = bufp;
		while(*src != '@' && *src != ';')
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
		if(*src == ';')
		{
			src++;
			bufp = ALIGN(bufp);
			p->iri.auth = bufp;
			while(*src && *src != '@')
			{
				/* Don't decode, so it can be extracted properly */
				src = iri__copychar(&bufp, src);
			}
			*bufp = 0;
			bufp++;
		}
		else
		{
			src++;
		}
	}
	if(NULL != p->iri.scheme)
	{
		sc = 1;
		for(t = p->iri.scheme; *t; t++)
		{
			if('+' == *t)
			{
				sc++;
			}
		}
		bufp = ALIGN(bufp);
		sl = (char **) (void *) bufp;
		bufp += (sc + 1) * sizeof(char *);
		sc = 0;
		cp = 0;
		bufp = ALIGN(bufp);
		sl[0] = bufp;
		for(t = p->iri.scheme; *t; t++)
		{
			if('+' == *t)
			{
				if(sl[sc][0])
				{
					sl[sc][cp] = 0;
					bufp++;
					sc++;
					bufp = ALIGN(bufp);
					sl[sc] = bufp;
					cp = 0;
				}
			}
			else
			{
				sl[sc][cp] = *t;
				bufp++;
				cp++;
			}
		}
		if(sl[sc][0])
		{
			sl[sc][cp] = 0;
			sc++;
			bufp++;
		}
		sl[sc] = NULL;
		p->iri.schemelist = (const char **) sl;
		p->iri.nschemes = sc;
		bufp++;
	}
	bufp = ALIGN(bufp);
	p->iri.host = bufp;
	while(*src && *src != ':' && *src != '/' && *src != '?' && *src != '#')
	{
		src = iri__copychar_decode(&bufp, src, 0);
	}
	*bufp = 0;
	bufp++;
	if(*src == ':')
	{
		/* Port part */
		src++;
		endp = (char *) src;
		p->iri.port = strtol(src, &endp, 10);
		src = endp;
	}
	if(*src == '/')
	{
		bufp = ALIGN(bufp);
		p->iri.path = bufp;
		while(*src && *src != '?' && *src != '#')
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
	}
	if(*src == '?')
	{
		bufp = ALIGN(bufp);
		p->iri.query = bufp;
		src++;
		while(*src && *src != '#')
		{
			/* Don't actually decode the query itself, otherwise it
			 * can't be reliably split */
			src = iri__copychar(&bufp, src);
		}
		*bufp = 0;
		bufp++;
	}
	if(*src == '#')
	{
		bufp = ALIGN(bufp);
		p->iri.anchor = bufp; 
		while(*src)
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
	}
	if(*src)
	{
		/* Still stuff left? It must be a path... of sorts */
		bufp = ALIGN(bufp);
		p->iri.path = bufp; 
		while(*src && *src != '?' && *src != '#')
		{
			src = iri__copychar_decode(&bufp, src, 0);
		}
		*bufp = 0;
		bufp++;
	}
	return p;
}





