/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 * ALPS Project: Algorithms and Libraries for Physics Simulations                  *
 *                                                                                 *
 * ALPS Libraries                                                                  *
 *                                                                                 *
 * Copyright (C) 2010 - 2011 by Lukas Gamper <gamperl@gmail.com>                   *
 *                                                                                 *
 * This software is part of the ALPS libraries, published under the ALPS           *
 * Library License; you can use, redistribute it and/or modify it under            *
 * the terms of the license, either version 1 or (at your option) any later        *
 * version.                                                                        *
 *                                                                                 *
 * You should have received a copy of the ALPS Library License along with          *
 * the ALPS Libraries; see the file LICENSE.txt. If not, the license is also       *
 * available from http://alps.comp-phys.org/.                                      *
 *                                                                                 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT       *
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE       *
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,     *
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER     *
 * DEALINGS IN THE SOFTWARE.                                                       *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_HPP
#define ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_HPP

#include <alps/hdf5/archive.hpp>

#include <boost/shared_array.hpp>

namespace alps {

    #define ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_MAKE_PVP(ptr_type, arg_type)                                                                                           \
        template <typename T> hdf5::detail::make_pvp_proxy<std::pair<ptr_type, std::vector<std::size_t> > > make_pvp(                                               \
              std::string const & path                                                                                                                              \
            , arg_type value                                                                                                                                        \
            , std::size_t size                                                                                                                                      \
        ) {                                                                                                                                                         \
            return hdf5::detail::make_pvp_proxy<std::pair<ptr_type, std::vector<std::size_t> > >(                                                                   \
                  path                                                                                                                                              \
                , std::make_pair(value.get(), std::vector<std::size_t>(1, size))                                                                                    \
            );                                                                                                                                                      \
        }                                                                                                                                                           \
                                                                                                                                                                    \
        template <typename T> hdf5::detail::make_pvp_proxy<std::pair<ptr_type, std::vector<std::size_t> > > make_pvp(                                               \
              std::string const & path                                                                                                                              \
            , arg_type value                                                                                                                                        \
            , std::vector<std::size_t> const & size                                                                                                                 \
        ) {                                                                                                                                                         \
            return hdf5::detail::make_pvp_proxy<std::pair<ptr_type, std::vector<std::size_t> > >(path, std::make_pair(value.get(), size));                          \
        }
    ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_MAKE_PVP(T *, boost::shared_array<T> &)
    ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_MAKE_PVP(T const *, boost::shared_array<T> const &)
    #undef ALPS_NGS_HDF5_BOOST_SHARED_ARRAY_MAKE_PVP

}

#endif
