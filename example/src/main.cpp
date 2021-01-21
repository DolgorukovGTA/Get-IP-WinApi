#include <ipinfo/ipinfo.hpp>
#include <fmt/core.h>
#include <cstdint>

namespace app
{
    void show_ip_info(
            const std::string &ip,
            const std::string &lang);

    void show_ip_info_ex(
            const std::string &ip,
            const std::string &lang);
}

int
main(void)
{
    // app::show_ip_info("8.8.8.8", "english");
    app::show_ip_info_ex("2001:4860:4860::888", "russian");

    return 0;
}

void
app::show_ip_info(
        const std::string &ip,
        const std::string &lang)
{
    ipinfo::interface::informer informer{};
    ipinfo::types::error        error{};

    informer.set_ip(ip);
    informer.set_lang(lang);
    informer.run();

    fmt::print("IP: {:s}\n", informer.get_ip());
    fmt::print("IP type: {:s}\n", informer.get_ip_type());
    fmt::print("Continent: {:s}\n", informer.get_continent());
    fmt::print("Continent code: {}\n", informer.get_continent_code());
    fmt::print("County: {:s}\n", informer.get_country());
    fmt::print("Country code: {:s}\n", informer.get_country_code());
    fmt::print("Country capital: {:s}\n", informer.get_country_capital());
    fmt::print("Country phone code: {:s}\n", informer.get_country_ph_code());
    fmt::print("Country neighbors: {:s}\n", informer.get_country_neighbors());
    fmt::print("Region: {:s}\n", informer.get_region());
    fmt::print("Region code: {:s}\n", informer.get_region_code());
    fmt::print("City: {:s}\n", informer.get_city());
    fmt::print("City district: {:s}\n", informer.get_city_district());
    fmt::print("ZIP code: {:s}\n", informer.get_zip_code());
    fmt::print("Latitude: {:.2f}\n", informer.get_latitude());
    fmt::print("Longitude: {:.2f}\n", informer.get_longitude());
    fmt::print("Timezone: {:s}\n", informer.get_timezone());
    fmt::print("City timezone: {:s}\n", informer.get_city_timezone());
    fmt::print("Timezone GMT: {:s}\n", informer.get_timezone_gmt());
    fmt::print("GMT offset: {:d}\n", informer.get_gmt_offset());
    fmt::print("DST offset: {:d}\n", informer.get_dst_offset());
    fmt::print("ISP: {:s}\n", informer.get_isp());
    fmt::print("AS: {:s}\n", informer.get_as());
    fmt::print("Organization: {:s}\n", informer.get_org());
    fmt::print("Reverse DNS lookup: {:s}\n", informer.get_reverse_dns());
    fmt::print("Hosting, data center: {:d}\n", informer.get_hosting_status());
    fmt::print("Proxy, VPN, Tor usage: {:d}\n", informer.get_proxy_status());
    fmt::print("Mobile connection usage: {:d}\n", informer.get_mobile_status());
    fmt::print("Currency: {:s}\n", informer.get_currency());
    fmt::print("Currency code: {:s}\n", informer.get_currency_code());
    fmt::print("Currency symbol: {:s}\n", informer.get_currency_symbol());
    fmt::print("Currency exchange rate to USD: {:.2f}\n", informer.get_currency_rates());
    fmt::print("Currency plural: {:s}\n", informer.get_currency_plural());

    return;
}

void
app::show_ip_info_ex(
        const std::string &ip,
        const std::string &lang)
{
    ipinfo::interface::informer informer{ip, lang, 0u};
    ipinfo::types::error        error{};

    informer.run();

    ipinfo::types::node<std::string>  str_cont{};
    ipinfo::types::node<std::int32_t> i32_cont{};
    ipinfo::types::node<double>       dbl_cont{};
    ipinfo::types::node<bool>         bool_cont{};

    // printing below isn't such of good
    // we need to find a compact solution

    str_cont = informer.get_ip_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed}, // this is a bit field, OK? - Sure!
            str_cont.host);

    str_cont = informer.get_ip_type_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_continent_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{(str_cont.is_parsed)},
            str_cont.host);

    str_cont= informer.get_continent_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_country_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_country_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_country_capital_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_country_ph_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_country_neighbors_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_region_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_region_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_city_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_city_district_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_zip_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    dbl_cont = informer.get_latitude_ex();
    fmt::print("{:s}: {:.2f}; parsed: {:d}; host: {:s}\n",
            dbl_cont.desc,
            dbl_cont.val,
            bool{dbl_cont.is_parsed},
            dbl_cont.host);

    dbl_cont = informer.get_longitude_ex();
    fmt::print("{:s}: {:.2f}; parsed: {:d}; host: {:s}\n",
            dbl_cont.desc,
            dbl_cont.val,
            bool{dbl_cont.is_parsed},
            dbl_cont.host);

    str_cont = informer.get_timezone_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_city_timezone_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_timezone_gmt_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    i32_cont = informer.get_gmt_offset_ex();
    fmt::print("{:s}: {:d}; parsed: {:d}; host: {:s}\n",
            i32_cont.desc,
            i32_cont.val,
            bool{i32_cont.is_parsed},
            i32_cont.host);

    i32_cont = informer.get_dst_offset_ex();
    fmt::print("{:s}: {:d}; parsed: {:d}; host: {:s}\n",
            i32_cont.desc,
            i32_cont.val,
            bool{i32_cont.is_parsed},
            i32_cont.host);

    str_cont = informer.get_isp_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_as_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_org_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_reverse_dns_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    bool_cont = informer.get_proxy_status_ex();
    fmt::print("{:s}: {:d}; parsed: {:d}; host: {:s}\n",
            bool_cont.desc,
            bool_cont.val,
            bool{bool_cont.is_parsed},
            bool_cont.host);

    bool_cont = informer.get_mobile_status_ex();
    fmt::print("{:s}: {:d}; parsed: {:d}; host: {:s}\n",
            bool_cont.desc,
            bool_cont.val,
            bool{bool_cont.is_parsed},
            bool_cont.host);

    str_cont = informer.get_currency_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_currency_code_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    str_cont = informer.get_currency_symbol_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n",
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    dbl_cont = informer.get_currency_rates_ex();
    fmt::print("{:s}: {:.2f}; parsed: {:d}; host: {:s}\n",
            dbl_cont.desc,
            dbl_cont.val,
            bool{dbl_cont.is_parsed},
            dbl_cont.host);

    str_cont = informer.get_currency_plural_ex();
    fmt::print("{:s}: {:s}; parsed: {:d}; host: {:s}\n", 
            str_cont.desc,
            str_cont.val,
            bool{str_cont.is_parsed},
            str_cont.host);

    return;
}
