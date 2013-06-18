/**
 *   SFCGAL
 *
 *   Copyright (C) 2012-2013 Oslandia <infos@oslandia.com>
 *   Copyright (C) 2012-2013 IGN (http://www.ign.fr)
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _SFCGAL_ALGORITHM_ISVALID_H_
#define _SFCGAL_ALGORITHM_ISVALID_H_

#include <SFCGAL/Geometry.h>
#include <SFCGAL/Validity.h>

namespace SFCGAL {
namespace algorithm {

	/**
	 * @brief Check validity of a geometry
	 * @ingroup public_api
	 */
    const Validity isValid( const Geometry & g, const double & toleranceAbs= 1e-9 );

/**
 * Macro used to by-pass validity check
 */
#ifndef SFCGAL_NEVER_CHECK_VALIDITY
#  define SFCGAL_ASSERT_GEOMETRY_VALIDITY(g)                                                                \
   {                                                                                                        \
       const SFCGAL::Validity sfcgalAssertGeometryVal = SFCGAL::algorithm::isValid(g);           \
       if ( !sfcgalAssertGeometryVal ) {                                                                    \
           BOOST_THROW_EXCEPTION(Exception(                                                                 \
              ( boost::format("%s is invalid : %s") % g.asText() % sfcgalAssertGeometryVal.reason() ).str() \
           ));                                                                                              \
       }                                                                                                    \
   }
#else
#  define SFCGAL_ASSERT_GEOMETRY_VALIDITY(g)
#endif

}//algorithm
}//SFCGAL


#endif
