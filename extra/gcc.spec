*startfile:
%{!mandroid|tno-android-ld:%{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}}    crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s};:%{shared: crtbegin_so%O%s;:  %{static: crtbegin_static%O%s;: crtbegin_dynamic%O%s}}}

