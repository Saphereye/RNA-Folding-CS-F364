Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 50.00      0.02     0.02        1    20.00    20.00  stbi__do_zlib(stbi__zbuf*, char*, int, int, int)
 50.00      0.04     0.02        1    20.00    20.00  stbi__create_png_image_raw(stbi__png*, unsigned char*, unsigned int, int, unsigned int, unsigned int, int, int)
  0.00      0.04     0.00     1121     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long)
  0.00      0.04     0.00     1035     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long)
  0.00      0.04     0.00      430     0.00     0.00  stbi__get16be(stbi__context*)
  0.00      0.04     0.00      291     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...)
  0.00      0.04     0.00      137     0.00     0.00  stbi__stdio_read(void*, char*, int)
  0.00      0.04     0.00      132     0.00     0.00  stbi__zbuild_huffman(stbi__zhuffman*, unsigned char const*, int)
  0.00      0.04     0.00       97     0.00     0.00  drawTexturedQuad()
  0.00      0.04     0.00       97     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long)
  0.00      0.04     0.00       97     0.00     0.00  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00      0.04     0.00        8     0.00     0.00  void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&)
  0.00      0.04     0.00        4     0.00     0.00  void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*)
  0.00      0.04     0.00        2     0.00     0.00  create_matrix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int const&)
  0.00      0.04     0.00        2     0.00     0.00  stbi__get8(stbi__context*)
  0.00      0.04     0.00        2     0.00     0.00  void Logger::log<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
  0.00      0.04     0.00        2     0.00     0.00  void Logger::info<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
  0.00      0.04     0.00        2     0.00     0.00  std::vector<int, std::allocator<int> >* std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > const&)
  0.00      0.04     0.00        1     0.00    40.00  loadTexture(char const*)
  0.00      0.04     0.00        1     0.00     0.00  dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00      0.04     0.00        1     0.00     0.00  traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int)
  0.00      0.04     0.00        1     0.00    40.00  stbi__load_main(stbi__context*, int*, int*, int*, int, stbi__result_info*, int)
  0.00      0.04     0.00        1     0.00    40.00  stbi__parse_png_file(stbi__png*, int, int)
  0.00      0.04     0.00        1     0.00    40.00  stbi__load_and_postprocess_8bit(stbi__context*, int*, int*, int*, int)
  0.00      0.04     0.00        1     0.00     0.00  void Logger::print_to_stream<int, int>(std::ostream&, char const*, int, int)
  0.00      0.04     0.00        1     0.00     0.00  void Logger::log<int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int)
  0.00      0.04     0.00        1     0.00     0.00  void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int)
  0.00      0.04     0.00        1     0.00     0.00  void Logger::log<unsigned long>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, unsigned long)
  0.00      0.04     0.00        1     0.00    40.00  stbi_load

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2022 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) for 25.00% of 0.04 seconds

index % time    self  children    called     name
                0.00    0.04       1/1           loadTexture(char const*) [3]
[1]    100.0    0.00    0.04       1         stbi_load [1]
                0.00    0.04       1/1           stbi__load_and_postprocess_8bit(stbi__context*, int*, int*, int*, int) [6]
                0.00    0.00       1/137         stbi__stdio_read(void*, char*, int) [61]
-----------------------------------------------
                                                 <spontaneous>
[2]    100.0    0.00    0.04                 main [2]
                0.00    0.04       1/1           loadTexture(char const*) [3]
                0.00    0.00       3/4           void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*) [67]
                0.00    0.00       2/2           create_matrix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int const&) [68]
                0.00    0.00       2/2           void Logger::info<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [71]
                0.00    0.00       1/1           traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [74]
                0.00    0.00       1/1           void Logger::log<unsigned long>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, unsigned long) [78]
                0.00    0.00       1/1           void Logger::log<int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int) [76]
                0.00    0.00       1/1           dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [73]
-----------------------------------------------
                0.00    0.04       1/1           main [2]
[3]    100.0    0.00    0.04       1         loadTexture(char const*) [3]
                0.00    0.04       1/1           stbi_load [1]
                0.00    0.00       1/4           void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*) [67]
                0.00    0.00       1/1           void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int) [77]
-----------------------------------------------
                0.00    0.04       1/1           stbi__load_and_postprocess_8bit(stbi__context*, int*, int*, int*, int) [6]
[4]    100.0    0.00    0.04       1         stbi__load_main(stbi__context*, int*, int*, int*, int, stbi__result_info*, int) [4]
                0.00    0.04       1/1           stbi__parse_png_file(stbi__png*, int, int) [5]
-----------------------------------------------
                0.00    0.04       1/1           stbi__load_main(stbi__context*, int*, int*, int*, int, stbi__result_info*, int) [4]
[5]    100.0    0.00    0.04       1         stbi__parse_png_file(stbi__png*, int, int) [5]
                0.02    0.00       1/1           stbi__do_zlib(stbi__zbuf*, char*, int, int, int) [7]
                0.02    0.00       1/1           stbi__create_png_image_raw(stbi__png*, unsigned char*, unsigned int, int, unsigned int, unsigned int, int, int) [8]
                0.00    0.00     430/430         stbi__get16be(stbi__context*) [59]
                0.00    0.00      68/137         stbi__stdio_read(void*, char*, int) [61]
                0.00    0.00       2/2           stbi__get8(stbi__context*) [69]
-----------------------------------------------
                0.00    0.04       1/1           stbi_load [1]
[6]    100.0    0.00    0.04       1         stbi__load_and_postprocess_8bit(stbi__context*, int*, int*, int*, int) [6]
                0.00    0.04       1/1           stbi__load_main(stbi__context*, int*, int*, int*, int, stbi__result_info*, int) [4]
-----------------------------------------------
                0.02    0.00       1/1           stbi__parse_png_file(stbi__png*, int, int) [5]
[7]     50.0    0.02    0.00       1         stbi__do_zlib(stbi__zbuf*, char*, int, int, int) [7]
                0.00    0.00     132/132         stbi__zbuild_huffman(stbi__zhuffman*, unsigned char const*, int) [62]
-----------------------------------------------
                0.02    0.00       1/1           stbi__parse_png_file(stbi__png*, int, int) [5]
[8]     50.0    0.02    0.00       1         stbi__create_png_image_raw(stbi__png*, unsigned char*, unsigned int, int, unsigned int, unsigned int, int, int) [8]
-----------------------------------------------
                0.00    0.00       1/1121        void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int) [77]
                0.00    0.00       1/1121        void Logger::log<unsigned long>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, unsigned long) [78]
                0.00    0.00       1/1121        void Logger::log<int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int) [76]
                0.00    0.00       2/1121        void Logger::log<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [70]
                0.00    0.00       4/1121        void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*) [67]
                0.00    0.00     388/1121        display() [82]
                0.00    0.00     724/1121        dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [73]
[57]     0.0    0.00    0.00    1121         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
                0.00    0.00     300/1035        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long) [58]
-----------------------------------------------
                0.00    0.00     300/1035        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
                0.00    0.00     735/1035        dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [73]
[58]     0.0    0.00    0.00    1035         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long) [58]
-----------------------------------------------
                0.00    0.00     430/430         stbi__parse_png_file(stbi__png*, int, int) [5]
[59]     0.0    0.00    0.00     430         stbi__get16be(stbi__context*) [59]
                0.00    0.00      68/137         stbi__stdio_read(void*, char*, int) [61]
-----------------------------------------------
                0.00    0.00     291/291         display() [82]
[60]     0.0    0.00    0.00     291         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...) [60]
-----------------------------------------------
                0.00    0.00       1/137         stbi_load [1]
                0.00    0.00      68/137         stbi__parse_png_file(stbi__png*, int, int) [5]
                0.00    0.00      68/137         stbi__get16be(stbi__context*) [59]
[61]     0.0    0.00    0.00     137         stbi__stdio_read(void*, char*, int) [61]
-----------------------------------------------
                0.00    0.00     132/132         stbi__do_zlib(stbi__zbuf*, char*, int, int, int) [7]
[62]     0.0    0.00    0.00     132         stbi__zbuild_huffman(stbi__zhuffman*, unsigned char const*, int) [62]
-----------------------------------------------
                0.00    0.00      97/97          display() [82]
[63]     0.0    0.00    0.00      97         drawTexturedQuad() [63]
-----------------------------------------------
                0.00    0.00      97/97          std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [65]
[64]     0.0    0.00    0.00      97         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long) [64]
-----------------------------------------------
                0.00    0.00      97/97          display() [82]
[65]     0.0    0.00    0.00      97         std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [65]
                0.00    0.00      97/97          std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long) [64]
-----------------------------------------------
                0.00    0.00       8/8           traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [74]
[66]     0.0    0.00    0.00       8         void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&) [66]
-----------------------------------------------
                0.00    0.00       1/4           loadTexture(char const*) [3]
                0.00    0.00       3/4           main [2]
[67]     0.0    0.00    0.00       4         void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*) [67]
                0.00    0.00       4/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------
                0.00    0.00       2/2           main [2]
[68]     0.0    0.00    0.00       2         create_matrix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int const&) [68]
                0.00    0.00       2/2           std::vector<int, std::allocator<int> >* std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > const&) [72]
-----------------------------------------------
                0.00    0.00       2/2           stbi__parse_png_file(stbi__png*, int, int) [5]
[69]     0.0    0.00    0.00       2         stbi__get8(stbi__context*) [69]
-----------------------------------------------
                0.00    0.00       2/2           void Logger::info<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [71]
[70]     0.0    0.00    0.00       2         void Logger::log<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [70]
                0.00    0.00       2/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------
                0.00    0.00       2/2           main [2]
[71]     0.0    0.00    0.00       2         void Logger::info<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [71]
                0.00    0.00       2/2           void Logger::log<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [70]
-----------------------------------------------
                0.00    0.00       2/2           create_matrix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int const&) [68]
[72]     0.0    0.00    0.00       2         std::vector<int, std::allocator<int> >* std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > const&) [72]
-----------------------------------------------
                0.00    0.00       1/1           main [2]
[73]     0.0    0.00    0.00       1         dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [73]
                0.00    0.00     735/1035        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long) [58]
                0.00    0.00     724/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------
                                  78             traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [74]
                0.00    0.00       1/1           main [2]
[74]     0.0    0.00    0.00       1+78      traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [74]
                0.00    0.00       8/8           void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&) [66]
                                  78             traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [74]
-----------------------------------------------
                0.00    0.00       1/1           void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int) [77]
[75]     0.0    0.00    0.00       1         void Logger::print_to_stream<int, int>(std::ostream&, char const*, int, int) [75]
-----------------------------------------------
                0.00    0.00       1/1           main [2]
[76]     0.0    0.00    0.00       1         void Logger::log<int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int) [76]
                0.00    0.00       1/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------
                0.00    0.00       1/1           loadTexture(char const*) [3]
[77]     0.0    0.00    0.00       1         void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int) [77]
                0.00    0.00       1/1           void Logger::print_to_stream<int, int>(std::ostream&, char const*, int, int) [75]
                0.00    0.00       1/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------
                0.00    0.00       1/1           main [2]
[78]     0.0    0.00    0.00       1         void Logger::log<unsigned long>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, unsigned long) [78]
                0.00    0.00       1/1121        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long) [57]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2022 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

   [3] loadTexture(char const*) [5] stbi__parse_png_file(stbi__png*, int, int) [71] void Logger::info<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
  [68] create_matrix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int const&) [62] stbi__zbuild_huffman(stbi__zhuffman*, unsigned char const*, int) [60] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > __gnu_cxx::__to_xstring<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(int (*)(char*, unsigned long, char const*, __va_list_tag*), unsigned long, char const*, ...)
  [63] drawTexturedQuad()      [8] stbi__create_png_image_raw(stbi__png*, unsigned char*, unsigned int, int, unsigned int, unsigned int, int, int) [72] std::vector<int, std::allocator<int> >* std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >*, unsigned long, std::vector<int, std::allocator<int> > const&)
  [73] dot_bracket_to_dot(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [6] stbi__load_and_postprocess_8bit(stbi__context*, int*, int*, int*, int) [66] void std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >::_M_realloc_insert<std::pair<int, int> >(__gnu_cxx::__normal_iterator<std::pair<int, int>*, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > >, std::pair<int, int>&&)
  [74] traceback(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >&, int, int) [75] void Logger::print_to_stream<int, int>(std::ostream&, char const*, int, int) [57] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long)
  [69] stbi__get8(stbi__context*) [67] void Logger::log<>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*) [64] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long)
   [7] stbi__do_zlib(stbi__zbuf*, char*, int, int, int) [70] void Logger::log<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [58] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long)
  [59] stbi__get16be(stbi__context*) [76] void Logger::log<int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int) [65] std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
   [4] stbi__load_main(stbi__context*, int*, int*, int*, int, stbi__result_info*, int) [77] void Logger::log<int, int>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, int, int) [1] stbi_load
  [61] stbi__stdio_read(void*, char*, int) [78] void Logger::log<unsigned long>(char const*, std::basic_string_view<char, std::char_traits<char> > const&, char const*, unsigned long)
