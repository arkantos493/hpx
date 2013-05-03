//  Copyright (c) 2013 Jeroen Habraken
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx_fwd.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/components/security/certificate_authority_base.hpp>
#include <hpx/components/security/server/root_certificate_authority.hpp>
#include <hpx/components/security/server/subordinate_certificate_authority.hpp>

int hpx_main(boost::program_options::variables_map &)
{
    {
        using namespace hpx::components::security;

        certificate_authority_base root_ca(
            hpx::components::new_<
                server::root_certificate_authority
            >(hpx::find_here()));

        // root_ca.test();


        certificate_authority_base subordinate_ca(
            hpx::components::new_<
                server::subordinate_certificate_authority
            >(hpx::find_here(), root_ca.get_gid()));

        subordinate_ca.test();
    }

    return hpx::finalize();
}

int main(int argc, char *argv[])
{
    boost::program_options::options_description desc_commandline(
        "usage: " HPX_APPLICATION_STRING " [options]");

    return hpx::init(desc_commandline, argc, argv);
}
