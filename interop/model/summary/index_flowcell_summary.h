/** Index summary for entire flowcell
 *
 *  @file
 *  @date  5/10/16
 *  @version 1.0
 *  @copyright GNU Public License.
 */
#pragma once
#include <vector>
#include "interop/util/assert.h"
#include "interop/model/model_exceptions.h"
#include "interop/model/summary/index_lane_summary.h"

namespace illumina { namespace interop { namespace model { namespace summary {

    class index_flowcell_summary
    {
    public:
        /** Lane summary vector type */
        typedef std::vector<index_lane_summary> lane_summary_vector_t;
    public:
        /** Reference to lane summary */
        typedef lane_summary_vector_t::reference reference;
        /** Constant reference to lane summary */
        typedef lane_summary_vector_t::const_reference const_reference;
        /** Random access iterator to vector of lane summary */
        typedef lane_summary_vector_t::iterator iterator;
        /** Constant random access iterator to vector of lane summary */
        typedef lane_summary_vector_t::const_iterator const_iterator;
        /** Unsigned integral type (usually size_t) */
        typedef lane_summary_vector_t::size_type size_type;
    public:
        /** Constructor
         */
        index_flowcell_summary()
        {
        }
        
    public: 
        /** Get reference to lane summary at given index
         *
         * @param n index
         * @return reference to lane summary
         */
        reference operator[](const size_type n) throw( model::index_out_of_bounds_exception )
        {
            if(n >= m_lane_summaries.size()) throw index_out_of_bounds_exception("Read index exceeds read count");
            return m_lane_summaries[n];
        }
        /** Get constant reference to lane summary at given index
         *
         * @param n index
         * @return constant reference to lane summary
         */
        const_reference operator[](const size_type n)const throw( model::index_out_of_bounds_exception )
        {
            if(n >= m_lane_summaries.size()) throw index_out_of_bounds_exception("Read index exceeds read count");
            return m_lane_summaries[n];
        }
        /** Get reference to lane summary at given index
         *
         * @param n index
         * @return reference to lane summary
         */
        reference at(const size_type n) throw( model::index_out_of_bounds_exception )
        {
            if(n >= m_lane_summaries.size()) throw index_out_of_bounds_exception("Read index exceeds read count");
            return m_lane_summaries[n];
        }
        /** Get constant reference to lane summary at given index
         *
         * @param n index
         * @return constant reference to lane summary
         */
        const_reference at(const size_type n)const throw( model::index_out_of_bounds_exception )
        {
            if(n >= m_lane_summaries.size()) throw index_out_of_bounds_exception("Read index exceeds read count");
            return m_lane_summaries[n];
        }
        /** Get number of summaries by read
         *
         * @return number of summaries by read
         */
        size_t size()const
        {
            return m_lane_summaries.size();
        }
        /** Get random access iterator to start of summaries by read
         *
         * @return random access iterator
         */
        iterator begin()
        {
            return m_lane_summaries.begin();
        }
        /** Get random access iterator to end of summaries by read
         *
         * @return random access iterator
         */
        iterator end()
        {
            return m_lane_summaries.end();
        }
        /** Get constant random access iterator to start of summaries by read
         *
         * @return constant random access iterator
         */
        const_iterator begin()const
        {
            return m_lane_summaries.begin();
        }
        /** Get constant random access iterator to end of summaries by read
         *
         * @return constant random access iterator
         */
        const_iterator end()const
        {
            return m_lane_summaries.end();
        }

    private:
        lane_summary_vector_t m_lane_summaries;
    };

}}}}
